#from maix import camera, display, image, nn, app, time
#from usartserial import UartSerial_ToSTM32
from kalmanfilter import KalmanFilter

class Hand_Tracker:
    def __init__(self,img_width,img_height,uart_serial=None):
        self.insKal1_x=KalmanFilter(LastP=-150,Now_P=-150,out=0,Kg=0,Q=0.2,R=2)
        self.insKal1_y=KalmanFilter(LastP=-150,Now_P=-150,out=0,Kg=0,Q=0.2,R=2)
        self.img_width=img_width
        self.img_height=img_height
        self.uart_serial=uart_serial

    def strformat(self,x):
        if x<0:
            #print(x)
            x_str=str(-x)
            x_len=len(x_str)
            x_str="-"+"0"*(3-x_len)+x_str
            return x_str
            #print("format:"+x_str)
        elif x>=0:
            #print(x)
            x_str=str(x)
            x_len=len(x_str)
            x_str="+"+"0"*(3-x_len)+x_str
            #print("format:"+x_str)
            return x_str

    def track_hands(self,hands):
        hand_num=0
        x0=0
        y0=0
        for hand in hands:
            x0=x0+int(hand.x+hand.w/2-self.img_width/2)
            y0=y0+int(hand.y+hand.h/2-self.img_height/2)
            hand_num+=1
        if hand_num!=0:
            x0=int(self.insKal1_x.filt_con(x0/hand_num))
            y0=int(self.insKal1_y.filt_con(y0/hand_num))
        
        msg="0"+self.strformat(x0)+self.strformat(y0)+"00"
        if self.uart_serial==None:
            return msg
        else:
            self.uart_serial.send(msg)

    def re_init(self):
        self.insKal1_x.re_init(LastP=-150,Now_P=-150,out=0,Kg=0,Q=0.2,R=2)
        self.insKal1_y.re_init(LastP=-150,Now_P=-150,out=0,Kg=0,Q=0.2,R=2)