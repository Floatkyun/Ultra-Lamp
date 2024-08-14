from paho.mqtt import client as mqtt
import uuid
import json
##

switch1 =0
servo_lr=0
servo_ud=0
rtsp=0
rtmp=0
rtmp_server_www=None

def set_rtmp(rtmp_):
    global rtmp
    rtmp=rtmp_

class Mqtt_device():

    def __init__(self, mt_ip, mt_user, mt_pwd,topic,Uartserial,rtsp_server=None,rtmp_server=None):#初始化并连接
        self.mt_ip = mt_ip
        self.mt_user = mt_user
        self.mt_pwd = mt_pwd
        self.mqttClient=self.connect()
        self.topic=topic

        self.Uartserial=Uartserial
        self.rtsp_server=rtsp_server
        self.rtmp_server=rtmp_server

    def bind_rtsp(self,rtsp_server):
        self.rtsp_server=rtsp_server

    def bind_rtmp(self,rtmp_server):
        self.rtmp_server=rtmp_server

    def on_connect(self, client, userdata, flags, rc):
        """一旦连接成功, 回调此方法"""
        rc_status = ["连接成功", "协议版本不正确", "客户端标识符无效", "服务器不可用", "用户名或密码不正确", "未经授权"]
        print("mqtt_connect：", rc_status[rc])
    
    def connect(self):
        mqttClient = mqtt.Client(mqtt.CallbackAPIVersion.VERSION1,str(uuid.uuid4()))
        mqttClient.on_connect = self.on_connect  # 返回连接状态的回调函数
        mqttClient.on_message = self.on_message  # 返回订阅消息回调函数
        mqttClient.username_pw_set(self.mt_user, self.mt_pwd)  # MQTT服务器账号密码
        mqttClient.connect(self.mt_ip, 1883, 60)  # MQTT地址、端口、心跳间隔（单位为秒）
        mqttClient.loop_start()  # 启用线程连接
        return mqttClient
        
    def on_message(self, client, userdata, msg):
        global servo_ud,servo_lr,switch1,rtsp,rtmp,rtmp_server_www
        result = msg.payload.decode('gb2312', 'ignore')
        result=json.loads(result)
        print(result)
        if "rtsp" in result.keys():
            #print("rtsp",int(result["rtsp"]))
            if rtsp!=int(result["rtsp"]):
                if self.rtsp_server != None:
                    if self.rtsp_server.server.rtsp_is_start():
                        if int(result["rtsp"])==1:
                            self.rtsp_server.rtsp_continue()
                            rtmp_server_www=self.rtsp_server.www
                        elif int(result["rtsp"])==0:
                            self.rtsp_server.rtsp_stop()
            rtsp=int(result["rtsp"])
            self.response()
        elif "rtmp" in result.keys():
            #print("rtmp",int(result["rtmp"]))
            if rtmp!=int(result["rtmp"]):
                if self.rtmp_server != None :
                    if int(result["rtmp"])==1:
                        self.rtmp_server.start()
                        
                    elif int(result["rtmp"])==0:
                        self.rtmp_server.stop()
                    rtmp=int(result["rtmp"])
            self.response()
        elif "switch" in result.keys():
            #print("switch",int(result["switch"]))
            if switch1!=int(result["switch"]):
                if self.Uartserial != None:
                    if int(result["switch"])==1:
                        msg="L100000000\n"
                        self.Uartserial.send(msg)
                        print("open light")
                    elif int(result["switch"])==0:
                        msg="L000000000\n"
                        self.Uartserial.send(msg)
                        print("close light")
            switch1=int(result["switch"])
            self.response()
        elif "method" in result.keys():
            result=result["params"]
            if "servo_lr" in result:
                print("servo_lr",int(result["servo_lr"]))
                servo_lr=servo_lr+int(result["servo_lr"])*5
            elif "servo_ud" in result:
                print("servo_ud",int(result["servo_ud"]))
                servo_ud=servo_ud+int(result["servo_ud"])*5

    def disconnect(self):
        self.mqttClient.loop_stop()
        print("停止连接")
        
    def subscribe(self,topic):
        self.mqttClient.subscribe(topic, 2)
    
    def publish(self,topic=None,text=""):
        if topic is None:
            topic=self.topic
        self.mqttClient.publish(topic, text, 2)
    
    def response(self):
        msg= """
        {
        "switch": %d,
        "rtmp": %d,
        "rtsp": %d,
        "www":%s
        }"""%(switch1,rtmp,rtsp,rtmp_server_www)
        self.publish(text=msg)
        #print(msg)
    
    def send_room_msg(self,temp,humi,CO2,lux,pre_temp,env_score):
        msg= """{
        "temp": %d,
        "humi": %d,
        "CO2": %d,
        "lux": %d,
        "pre_temp":%d,
        "env_score": %d
        }"""%(temp,humi,CO2,lux,pre_temp,env_score)
        self.publish(text=msg)
        #print(msg)

def mqtt_init(Uartserial,rtsp_server=None,rtmp_server=None):
    mqtt1=Mqtt_device(mt_ip="120.27.132.21",mt_user="MAIXCAM",mt_pwd="123456",topic="device/attributes",Uartserial=Uartserial,rtsp_server=rtsp_server,rtmp_server=rtmp_server)
    mqtt1.subscribe("device/attributes/MAIXCAM")
    mqtt1.subscribe("device/command/MAIXCAM")
    return mqtt1