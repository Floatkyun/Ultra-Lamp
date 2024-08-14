from maix.v1.machine import UART
from maix import  time
from work_detector import WorkDetector
from hand_tracker import Hand_Tracker
from maix import nn
from util import show_detect_result
from network_time import get_time_str
from guarder import Guarder
import res

temp=0
humi=0
CO2=0
lux=0
pre_temp=0
env_score=0

class UartSerial_ToSTM32:
    def __init__(self,chat_glm4v,audio_warn,email=None,rtmp=None,device="/dev/ttyS0",baud_rate=115200):
        self.uart_A = UART(device, baud_rate)
        self.mqtt=None
        self.email=email
        self.rtmp=rtmp
        self.work_detector=None
        self.hand_tracker=None
        self.hand_detector_model=None
        self.obj_detector_model=None
        self.hand_detector_path="/root/models/fusion_hand_ok_filter320320_hyp.mud"
        self.obj_detector_path="/root/models/fusion_desk_object_less_filtbook320320.mud"
        self.cam_channel=None
        self.work_detector_working=0
        self.guard_working=0
        self.guarder=None
        self.audio_warn=audio_warn
        self.chat_glm4v=chat_glm4v

    def send(self,msg):
        print("send:"+msg)
        self.uart_A.write(bytes(str(msg),encoding='utf-8'))

    def bind_mqtt(self,mqtt):
        self.mqtt=mqtt

    def time_cali(self):
        self.send(get_time_str())

    def init_work_detector_hand_tracker(self,img_width,img_height):
        self.cam=res.cam
        self.disp=res.dis
        if self.cam_channel ==None and self.cam!=None:
            #self.cam.close()
            self.cam_channel=self.cam.add_channel(img_width, img_height)
            #self.cam_channel=self.cam
        if self.hand_detector_model ==None:
            self.hand_detector_model=nn.YOLOv5(model=self.hand_detector_path)
        if self.obj_detector_model ==None:
            self.obj_detector_model=nn.YOLOv5(model=self.obj_detector_path)
        if self.hand_tracker ==None:
            self.hand_tracker=Hand_Tracker(img_width,img_height,None)
        if self.work_detector==None:
            self.work_detector=WorkDetector(self.obj_detector_model)
        self.work_detector.run_statistics_analyser()
        #print("init OK")

    def run_work_detector_hand_tracker(self):
        if self.cam_channel !=None and self.obj_detector_model!=None and self.hand_detector_model!=None and self.work_detector !=None and self.hand_tracker!=None and self.disp!=None:
            img = self.cam_channel.read()
            objs = self.obj_detector_model.detect(img, conf_th = 0.6, iou_th = 0.45)
            hands=self.hand_detector_model.detect(img, conf_th = 0.5, iou_th = 0.45)
            
            self.work_detector.current_work(objs,hands)
            self.send(self.hand_tracker.track_hands(hands))
            if not self.work_detector.minute_workQ.empty():
                time.sleep_ms(50)
            while not self.work_detector.minute_workQ.empty():
                temp_data=self.work_detector.minute_workQ.get(False)
                if temp_data==None:
                    msg="w0000000000"
                    self.send(msg)
                    print(msg)
                else:
                    msg="w"
                    for item in temp_data:
                        msg=msg+str(item)
                    msg=msg+"0000"
                    self.send(msg)
                    print(msg)
                #self.uart_A.write(bytes(str(temp_data), encoding='utf-8'))
            img=show_detect_result(show_detect_result(img,self.obj_detector_model,objs),self.hand_detector_model,hands)
            if self.disp!=None:
                self.disp.show(img)

    def destroy_work_detector_hand_tracker(self):
        self.cam=res.cam
        if self.work_detector!=None:
            self.work_detector.stop_statistics_analyser()
        self.cam_channel=None
        if self.cam!=None:
            self.cam.open()
        self.work_detector=None
        self.hand_tracker=None
        self.hand_detector_model=None
        self.obj_detector_model=None      
    
    def init_guard(self):
        self.guarder=Guarder(mail=self.email,cam=res.cam,rtmp=self.rtmp,dis=res.dis)
        self.guarder.start()

    def run_guard(self):
        if self.guarder!=None:
            self.guarder.run()

    def destroy_guard(self):
        if self.guarder!=None:
            self.guarder.stop()

    def recive_sign_num(self,x):
        if x[0]=='+':
            return  int(x[1:])
        elif x[0]=='-':
            return  -int(x[1:])

    def deal_input(self):
        if self.uart_A.any():
            #read_data = str(self.uart_A.read())[2:][:-1].split("\\\\n")[:-1]
            read_data = str(self.uart_A.read())[2:][:-1].split("\\n")[:-1]
            print(read_data)
            for data in read_data:
                if  data[0] == '0':
                    # x="0+12,023,00444,00400,+23,087\n"
                    #temp,humi,CO2,lux,pre_temp,env_score
                    data=data[1:].split(",")
                    if len(data)==6:
                        global temp,humi,CO2,lux,pre_temp,env_score
                        temp=self.recive_sign_num(data[0])
                        humi=int(data[1])
                        CO2=int(data[2])
                        lux=int(data[3])
                        pre_temp=self.recive_sign_num(data[4])
                        env_score=int(data[5])
                        print(temp,humi,CO2,lux,pre_temp,env_score)
                        if self.mqtt!=None and temp!=None:
                            self.mqtt.send_room_msg(temp,humi,CO2,lux,pre_temp,env_score)
                elif data[0] == 'w':
                    data=data[1:]
                    if data=="ork_detector_start" and self.work_detector_working==0:
                        if self.guard_working==1 :
                            self.guard_working=0
                            self.destroy_guard()
                        self.work_detector_working=1
                        self.init_work_detector_hand_tracker(320, 320)
                    elif data=="ork_detector_stop" and self.work_detector_working==1:
                        self.work_detector_working=0
                        self.destroy_work_detector_hand_tracker()
                
                elif data[0] == 'g':
                    data=data[1:]
                    if data=="uard_start" and  self.guard_working==0:
                        if self.work_detector_working==1 :
                            self.work_detector_working=0
                            self.destroy_work_detector_hand_tracker()
                        self.guard_working=1
                        self.init_guard()
                    elif data=="uard_stop" and  self.guard_working==1:
                        self.guard_working=0
                        self.rtmp.stop()
                        self.destroy_guard()

                elif data[0] == 'c':
                    data=data[1:]
                    if data=="hat_start":
                        if not self.chat_glm4v.started:
                            res.res_distroy()
                            #pass
                            self.chat_glm4v.start()
                    elif data=="hat_stop":
                        if  self.chat_glm4v.started:
                            #pass
                            self.chat_glm4v.stop()
                            res.res_init()
                elif data[0] == 'o':
                    data=data[1:]
                    #self.destroy_work_detector_hand_tracker()
                    #self.dis=None
                    #self.cam=None
                    #self.cam_channel=None
                    #res.res_distroy()
                    if data=="ver_game":
                        pass
                        #self.audio_warn.play(kind="game")
                    elif data=="ver_drink":
                        pass
                        #self.audio_warn.play(kind="drink")
                    elif data=="ver_work":
                        pass
                        #self.audio_warn.play(kind="work")
                    #res.res_init()
                    #self.init_work_detector_hand_tracker(320, 320)
                
                if data[0] == 't':
                    data=data[1:]
                    if data=="ime":
                        self.time_cali()

    def run(self):
        if self.work_detector_working==1:
            self.run_work_detector_hand_tracker()
        if self.guard_working==1:
            self.run_guard()
