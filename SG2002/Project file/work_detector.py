from types import NoneType
from maix import camera, display, image, nn, app, time
from kalmanfilter import KalmanFilter
#from queue import Queue
import schedule 
import multiprocessing
import numpy as np

class WorkDetector:
    def __init__(self,objct_detector,weight=[1,1,1,1,1,1]):
        #Book,Pen,Mobile phone,Computer keyboard,Computer mouse,Coffee cup
        self.labels=objct_detector.labels
        self.kal_list=[]
        self.now_work=[0]*len(self.labels)
        self.weight=weight
        self.temp_workQ=multiprocessing.Queue()
        self.minute_workQ=multiprocessing.Queue()
        self.process =None
        self.statistics_th=[5,5,5,5,5,5]
        for temp_index in self.labels:
            self.kal_list.append(KalmanFilter())

    def hand_overlap(self,desk_obj,hand_obj):
        overlap_area_x=(min(desk_obj.x+desk_obj.w,hand_obj.x+hand_obj.w)-max(desk_obj.x,hand_obj.x))
        overlap_area_y=(min(desk_obj.y+desk_obj.h,hand_obj.y+hand_obj.h)-max(desk_obj.y,hand_obj.y))
        overlap_area=overlap_area_x*overlap_area_y

        if overlap_area_x<0 or overlap_area_y<0:
            return 0
        else:
            return overlap_area/(hand_obj.w*hand_obj.h)

    def work_state_detector(self,objs,hands):
        work_state_list=[0]*len(self.labels)

        if len(hands)>0:
            for hand_obj in hands:
                for obj in objs:
                    #if self.labels[obj.class_id]!="person":
                    work_state_list[obj.class_id]+=self.hand_overlap(obj,hand_obj)
            return work_state_list
        else:
            return None
    
    def current_work(self,objs,hands):#return work state
        work_state_list=self.work_state_detector(objs,hands)
        if work_state_list!=None:
            for obj_index in range(len(work_state_list)):
                if work_state_list[obj_index] >0.15:
                    self.kal_list[obj_index].filt_dis(self.weight[obj_index])
                    work_state_list[obj_index]=1
                else:
                    self.kal_list[obj_index].filt_dis(0)
                    work_state_list[obj_index]=0
                self.now_work[obj_index]=self.kal_list[obj_index].state*self.kal_list[obj_index].out
            if max(self.now_work)==0:
                #work_name="No Work"# hands but no work
                self.temp_workQ.put(None)
                self.temp_workQ.put([0]*len(work_state_list))
                return -1
            else:                   #  work
                #work_name=self.labels[self.now_work.index(max(self.now_work))]
                self.temp_workQ.put(work_state_list)
                return self.now_work.index(max(self.now_work))
        else:
            for obj_index in range(len(self.labels)):
                self.kal_list[obj_index].filt_dis(0.5)
            #work_name=""           # no hands 
            self.temp_workQ.put(None)
            return None

    def work_name(self,work_state):#return work name
        if work_state ==None:
            return ""
        elif work_state ==-1:
            return "No_Work"
        else :
            return self.labels[work_state]

    def work_time_analyser(self,worktime_list,length=3):
        filtered_list=[]
        temp=0
        for i in worktime_list:
            if i==0:
                temp=max(0,temp-1)
            elif i==1:
                temp=length
            if temp>=1:
                filtered_list.append(1)
            else:
                filtered_list.append(0)
        for i in range(len(filtered_list)):
            if filtered_list[i]==0:
                if i<length-1 or filtered_list[i-1]==0:
                    pass
                else:
                    temp_index=1
                    while temp_index<length and (i-temp_index)>=0:
                        filtered_list[i-temp_index]=0
                        temp_index=temp_index+1   
        filtered_list_len=len(filtered_list)
        continue_work_time=0
        for i in range(filtered_list_len):
            if filtered_list[filtered_list_len-i-1]==1:
                continue_work_time+=1
            else:
                break
        return filtered_list,continue_work_time

    def drink_count_analyser(self,work_index_list):
        cup_index=self.labels.index("Coffee cup")
        temp_index=0
        count=0
        while temp_index<len(work_index_list):
            if work_index_list[temp_index]==None:
                temp_index+=1
            elif  work_index_list[temp_index][cup_index]==1:
                count+=1
                temp_index+=1
                while temp_index<len(work_index_list) and (work_index_list[temp_index]==None or work_index_list[temp_index][cup_index]==1):
                    temp_index+=1
                    if work_index_list[temp_index]==None:
                        break
            else:
                temp_index+=1
        return count

    def work_statistics(self,temp_workQ):
        temp_statistics=np.array([0]*len(self.labels))
        had_hands_num=0.0
        no_hands_num=0.0
        cup_index=self.labels.index("Coffee cup")
        while not temp_workQ.empty():
            temp_element =temp_workQ.get(False)
            if temp_element == None:
                no_hands_num+=1.0
            else:
                temp_statistics=temp_statistics+np.array(temp_element)
                had_hands_num+=1.0
        if had_hands_num+no_hands_num == 0:
            print("nodata")
            return None
        print("minute_statistics:",temp_statistics,end="")
        if no_hands_num/(had_hands_num+no_hands_num)>0.95:
            self.minute_workQ.put(None)
            print("None nohands")
        else:
            temp_statistics=list(temp_statistics)
            statistics=[0]*len(self.labels)
            if temp_statistics[cup_index]>0:
                statistics[cup_index]=1
                temp_statistics[cup_index]=0
            temp_index=temp_statistics.index(max(temp_statistics))
            if temp_statistics[temp_index]<self.statistics_th[temp_index]:
                statistics[temp_index]=0
                print("None th")
            else:
                statistics[temp_index]=1
                print(self.labels[temp_index])
            self.minute_workQ.put(statistics)

    def work_analyser(self,minute_work_list,worktime_list,phone_list):
        drink_count=self.drink_count_analyser(minute_work_list)
        filtered_worktime_list,continue_work_time=self.work_time_analyser(worktime_list=worktime_list,length=3)
        filtered_worktime_list,continue_phone_time=self.work_time_analyser(worktime_list=phone_list,length=3)
        print("work_analyser",minute_work_list,"共喝水",drink_count,"次")
        print("已经连续工作",continue_work_time,"分钟")
        print("已经连续看手机",continue_phone_time,"分钟")
    
    def strformat(self,data):
        pass

    def thread_statistics_analyser(self,temp_workQ,minute_workQ):
        cup_index=self.labels.index("Coffee cup")
        phone_index=self.labels.index("Mobile phone")
        minute_work_list=[]
        worktime_list=[]
        phone_list=[]
        schedule.every(5).seconds.do(self.work_statistics,temp_workQ)
        #schedule.every().minute.do(self.work_analyser,minute_work_list,worktime_list,phone_list)
        while True:
            #while not minute_workQ.empty():
                #temp_data=minute_workQ.get(False)
                #minute_work_list.append(temp_data)
                #if temp_data!=None and (not (temp_data[cup_index]==1 and sum(temp_data)==1)):
                    #worktime_list.append(1)
                    #if temp_data[phone_index]==1:
                        #phone_list.append(1)
                    #else:
                        #phone_list.append(0)
                #else:
                    #worktime_list.append(0)
                    #phone_list.append(0)
               
            schedule.run_pending()
            time.sleep(1)

    def run_statistics_analyser(self):
        self.process = multiprocessing.Process(target=self.thread_statistics_analyser,args=(self.temp_workQ,self.minute_workQ,))
        self.process.daemon = True
        self.process.start() 

    def stop_statistics_analyser(self):
        if self.process !=None:
            self.process.terminate()
            self.process.join()
            self.process=None



if __name__=="__main__":
    ###sys_init
    hand_detector = nn.YOLOv5(model="/root/models/fusion_hand_ok_filter320320_hyp.mud")
    detector = nn.YOLOv5(model="/root/models/fusion_desk_object_less_filtbook320320.mud")

    cam = camera.Camera(detector.input_width(), 320, detector.input_format())
    dis = display.Display()
    
    work_detector=WorkDetector(detector)

    ###main_loop
    while not app.need_exit():
        t = time.time_ms()
        img = cam.read()
        objs = detector.detect(img, conf_th = 0.6, iou_th = 0.45)
        hands=hand_detector.detect(img, conf_th = 0.5, iou_th = 0.45)
        work_state= work_detector.current_work(objs,hands)
        if work_state ==None:
            work_name=" "
        elif work_state ==-1:
            work_name="No_Work"
        else :
            work_name=work_detector.labels[work_state]   
        for obj in objs:
            img.draw_rect(obj.x, obj.y, obj.w, obj.h, color = image.COLOR_RED)
            msg = f'{detector.labels[obj.class_id]}: {obj.score:.2f}'
            img.draw_string(obj.x, obj.y, msg, color = image.COLOR_RED)
        for obj in hands:
            img.draw_rect(obj.x, obj.y, obj.w, obj.h, color = image.COLOR_RED)
            msg = f'{hand_detector.labels[obj.class_id]}: {obj.score:.2f}'
            img.draw_string(obj.x, obj.y, msg, color = image.COLOR_RED)
        img.draw_string(0, 0, work_name, color = image.COLOR_RED)
        print(work_name)
        dis.show(img)
        #print(f"time: {time.time_ms() - t}ms, fps: {1000 / (time.time_ms() - t)}")
