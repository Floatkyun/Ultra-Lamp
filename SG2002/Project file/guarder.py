from maix import camera, display, image, nn, app,time
import math
import numpy as np
import schedule
import mqtt 

class Guarder():
    def __init__(self,mail,cam,rtmp,dis=None):
        self.pose_detector=Pose_Detector()
        self.mail=mail
        self.cam=cam
        self.cam2=None
        self.rtmp=rtmp
        self.runing=False
        self.img_width=640
        self.img_height=480
        self.detector = None
        self.cooldown=True
        self.dis=dis
        schedule.every(5).minutes.do(self.cloo_down)
    
    def cloo_down(self):
        self.cooldown=True

    def start(self):
        if not self.runing:
            self.runing=True
            self.cam.close()
            self.cam2=self.cam.add_channel(320,320)
            self.detector = nn.YOLOv8(model="/root/models/yolov8n_pose.mud")

    def stop(self):
        if  self.runing:
            self.runing=False
            self.cam2=None
            self.cam.open()
            self.rtmp.start()
            mqtt.set_rtmp(1)
            self.detector = None
     
    def run(self):
        if  self.runing :
            img = self.cam2.read()
            objs = self.detector.detect(img, conf_th = 0.5, iou_th = 0.45, keypoint_th = 0.5)
            for obj in objs:
                img.draw_rect(obj.x, obj.y, obj.w, obj.h, color = image.COLOR_RED)
                #msg = f'{pose_detector.detect(obj)}: {obj.score:.2f}'
                #img.draw_string(obj.x, obj.y, msg, color = image.COLOR_RED)
                pose_result=self.pose_detector.detect(obj)
                self.send_warning(pose_result,img)
                print(pose_result)
                #self.detector.draw_pose(img, obj.points, 8 if self.detector.input_width() > 480 else 4, image.COLOR_RED)
            if self.dis !=None:
                self.dis.show(img) 

    def send_warning(self,pose_state,img):
        if self.cooldown:
            self.cooldown=False
            if pose_state != "Fall":
                self.mail.send(img=img)
            else :
                self.mail.send(img=img,text="UltraLamp检查到可能有人跌倒",subject='【守卫模式】UltraLamp检查到可能有人跌倒')
        self.stop()




class Pose_Detector():
    def __init__(self):
        self.HUMAN_ANGLE = 45
        self.ASPECT_RATIO = 0.5
        self.Vertical_threshold = 20
        self.Horizontal_threshold = 20
        self.ATHERPOSE = 0

    def convert_box(self,x,y,w,h):
        box=[x,y,x+w,y+h]
        return np.array(box)

    def convert_keypoints(self,keypoints_list):
        keypoints=[]
        for i in range(int(len(keypoints_list)/2)):
            if keypoints_list[2*i]<0 and keypoints_list[2*i+1]<0:
                keypoints.append([0,0,1])
            else:
                keypoints.append([keypoints_list[2*i],keypoints_list[2*i+1],1])
        #print(keypoints)
        return np.array(keypoints)
    

    def detect(self,obj):
        self.ATHERPOSE = 0
        boxes=self.convert_box(obj.x, obj.y, obj.w, obj.h)
        keypoints=self.convert_keypoints(obj.points)
        Left_Shoulder = keypoints[5][:2]
        if Left_Shoulder[0] + Left_Shoulder[1] == 0: self.ATHERPOSE += 2.5
        Right_Shoulder = keypoints[6][:2]
        if Right_Shoulder[0] + Right_Shoulder[1] == 0: self.ATHERPOSE += 2.5
        Left_Hip = keypoints[11][:2]
        if Left_Hip[0] + Left_Hip[1] == 0: self.ATHERPOSE += 1
        Right_Hip = keypoints[12][:2]
        if Right_Hip[0] + Right_Hip[1] == 0: self.ATHERPOSE += 1
        Left_Knee = keypoints[13][:2]
        if Left_Knee[0] + Left_Knee[1] == 0: self.ATHERPOSE += 1
        Right_Knee = keypoints[15][:2]
        if Right_Knee[0] + Right_Knee[1] == 0: self.ATHERPOSE += 1
        Left_Ankle = keypoints[15][:2]
        if Left_Ankle[0] + Left_Ankle[1] == 0: self.ATHERPOSE += 1
        Right_Ankle = keypoints[16][:2]
        if Right_Ankle[0] + Right_Ankle[1] == 0: self.ATHERPOSE += 1

        Shoulders_c = [(Left_Shoulder[0]+Right_Shoulder[0]) // 2,
                       (Left_Shoulder[1]+Right_Shoulder[1]) // 2]

        hips_c = [(Left_Hip[0]+Right_Hip[0]) // 2,
                  (Left_Hip[1]+Right_Hip[1]) // 2]

        Knee_c = [(Left_Knee[0]+Right_Knee[0]) // 2,
                  (Left_Knee[1]+Right_Knee[1]) // 2]

        Ankle_c = [(Left_Ankle[0] + Right_Ankle[0]) // 2,
                  (Left_Ankle[1] + Right_Ankle[1]) // 2]

        '''计算身体中心线与水平线夹角'''
        human_angle = self.getAnglebyline([Shoulders_c,hips_c,Knee_c],[[0, 0], [10, 0]])
        '''计算检测区域宽高比'''
        aspect_ratio = self.aspectRatio(boxes)
        '''计算肩部中心点与胯部中心点的垂直距离差'''
        human_shoulderhip = abs(Shoulders_c[1]-hips_c[1])

        '''计算肩部胯部膝盖夹角'''
        Hip_Knee_Shoulders_angle = self.getAnglebypoint(Shoulders_c,hips_c,Knee_c)
        Hip_Knee_Right_angle = self.getAnglebypoint(Right_Shoulder.tolist(),Right_Hip.tolist(),Right_Knee.tolist())

        '''计算胯部膝盖小腿夹角'''
        Ankle_Knee_Hip_angle = self.getAnglebypoint(hips_c,Knee_c,Ankle_c)
        Ankle_Knee_Right_angle = self.getAnglebypoint(Right_Hip.tolist(), Right_Knee.tolist(), Right_Ankle.tolist())

        '''计算胯部膝盖是否处于相似的垂直位置'''
        vertical_threshold =  Left_Knee[1] - Left_Shoulder[1]

        '''计算胯部膝盖是否处于相似的水平位置'''
        horizontal_threshold = Left_Shoulder[0] - Left_Knee[0]

        status_score = {'Stand': 0.0,
                        'Fall': 0.0,
                        'Sit': 0.0,
                        'other':0.0}
        _weight=''

        if self.ATHERPOSE>=5: status_score['other'] += 5.6
        '''判断Shoulder、Hip、Knee是否被检测到'''
        if Knee_c[0]== 0 and Knee_c[1]== 0 and hips_c[0]==0 and hips_c[1] == 0:
            status_score['Sit'] += 2
            status_score['Fall'] += -0.8*2
            status_score['Stand'] += -0.8*2
            #print(status_score)
            _weight = f'[1]Sit:+0.2, Fall:-1.6 ,Stand: -1.6'

        elif Shoulders_c[1] == 0 and Shoulders_c[0] == 0 and hips_c[0]==0 and hips_c[1] == 0:
            status_score['Sit'] += -0.8 * 2
            status_score['Fall'] += -0.8 * 2
            status_score['Stand'] += 0.69
            _weight = f'[1.1]Sit:+0.2, Fall:-1.6 ,Stand: -1.6'
        else:
            if 180>Ankle_Knee_Hip_angle[1]>125 and aspect_ratio[0] < self.ASPECT_RATIO:
                status_score['Stand'] += 1
            if 25>Ankle_Knee_Hip_angle[1]>-25 and aspect_ratio[0] > 1 / self.ASPECT_RATIO:
                status_score['Fall'] += 0.2
            if 125 > Ankle_Knee_Hip_angle[1] > 75:
                status_score['Sit'] += 1.2
            _weight = f'[1.3]Sit:+0.2, Fall:-1.6 ,Stand: -1.6'

        '''身体中心线与水平线夹角+-25'''
        if abs(human_angle-90) in range(90-self.HUMAN_ANGLE, 90):
            status_score['Fall'] += 1.6
            _weight=f'{_weight}, [2]Fall:+0.8, Sit:+0.1'
        else:
            status_score['Fall'] +=- 5*((90-abs(human_angle-90))/90)
            _weight = f'{_weight}, [3]Fall:+{-5*((90-abs(human_angle-90))/90)}'
        #print(human_angle)
        '''宽高比小与0.6则为站立'''
        if (aspect_ratio[0] < self.ASPECT_RATIO and human_angle in range(65, 115)):
            status_score['Stand'] += 0.4
            _weight = f'{_weight}, [4]Stand:+0.4'

        elif (aspect_ratio[0] > 1 / self.ASPECT_RATIO):  # 5/3
            status_score['Fall'] += 0.4
            _weight = f'{_weight}, [5]Fall:+0.4'

        if vertical_threshold < self.Vertical_threshold:
            status_score['Fall'] += 0.4
            status_score['Sit'] += -0.1
            _weight = f'{_weight}, [5.1]Fall:+0.4'
        if horizontal_threshold < self.Horizontal_threshold:
            status_score['Fall'] += 0.4
            status_score['Sit'] += -0.15
            _weight = f'{_weight}, [5.2]Fall:+0.4'


        if 25 < Hip_Knee_Shoulders_angle[1] < 145 and 75 < human_angle <125:
            status_score['Sit'] += 0.8
            status_score['Stand'] += -0.035
            if vertical_threshold > self.Vertical_threshold:
                status_score['Sit'] += +0.15
            _weight = f'{_weight}, [6]Stand:-0.035, Sit:+0.15'
        elif Hip_Knee_Shoulders_angle[1] > 120 and 75 < human_angle <125:
            status_score['Stand'] += 0.2
        elif Hip_Knee_Shoulders_angle[1] > 120 and -25 < human_angle <25:
            status_score['Fall'] += 0.2
        else:
            status_score['Fall'] += 0.05
            status_score['Stand'] += 0.05
            _weight = f'{_weight}, [7]Stand:+0.05, Fall:+0.05'

        if 25 < Ankle_Knee_Hip_angle[1] < 145 and 45 < human_angle <125:
            status_score['Sit'] += 0.8
            status_score['Stand'] += -0.035
            if vertical_threshold > self.Vertical_threshold:
                status_score['Sit'] += +0.15
            _weight = f'{_weight}, [8]Stand:+0.035, Sit:+0.15'
        else:
            status_score['Fall'] += 0.05
            status_score['Stand'] += 0.05
            _weight = f'{_weight}, [9]Stand:+0.05, Sit:+0.05'

        if 65 < Hip_Knee_Right_angle[1] < 145 and 45 < human_angle <125:
            status_score['Sit'] += 0.8
            if vertical_threshold > self.Vertical_threshold:
                status_score['Sit'] += +0.15
        else:
            status_score['Fall'] += 0.05
            status_score['Stand'] += 0.05

        #print(_weight)
        #print(status_score)

        score_max, status_max = max(zip(status_score.values(), status_score.keys()))

        '''输出计算参数'''
        header = ['检测类型 ', '计算结果']
        row = [['关键点',keypoints[0][:3]],
               ['肩部中心点',Shoulders_c],
               ['胯部中心点' ,hips_c],
               ['小腿中心点' ,Knee_c],
               ['肘部中心点' ,Ankle_c],
               ['身体中心线与水平线夹角', human_angle],
               ['宽高比', f'{aspect_ratio[0]} ,w:{aspect_ratio[1]} ,H:{aspect_ratio[2]}'],
               ['肩部中心点与胯部中心点的垂直距离差', human_shoulderhip],
               ['肩部胯部膝盖中心点夹角', Hip_Knee_Shoulders_angle],
               ['胯部膝盖小腿中心点夹角', Ankle_Knee_Hip_angle],
               ['右肩部胯部膝盖夹角', Hip_Knee_Right_angle],
               ['右胯部膝盖小腿夹角', Ankle_Knee_Right_angle],
               ['胯部膝盖是否处于相似的垂直位置', vertical_threshold],
               ['估计结果', status_score]]
        #print(tb(row, header, tablefmt='psql'))

        return status_max

    def getAnglebyline(self,line1, line2):
        """
        计算两条线段之间的夹角
        :param line1:[[3.0, 8.0], [5.0, 10.0]]
        :param line2:[[6.0, 1.0], [6.0, 15.0]]
        :return:
        """
        try:
            dx1 = (line1[0][0] - line1[1][0])
            dy1 = (line1[0][1] - line1[1][1])
            dx2 = line2[0][0] - line2[1][0]
            dy2 = line2[0][1] - line2[1][1]
            angle1 = math.atan2(dy1, dx1)
            angle1 = int(angle1 * 180 / math.pi)
            # print(angle1)
            angle2 = math.atan2(dy2, dx2)
            angle2 = int(angle2 * 180 / math.pi)
            # print(angle2)
            if angle1 * angle2 >= 0:
                insideAngle = abs(angle1 - angle2)
            else:
                insideAngle = abs(angle1) + abs(angle2)
                if insideAngle > 180:
                    insideAngle = 360 - insideAngle
            insideAngle = insideAngle % 180
            return insideAngle
        except ZeroDivisionError:
            print("线段不存在，无法计算两条直线夹角。")

    def aspectRatio(self,boxes):
        try:
            x1, y1, x2, y2 = boxes
            W = x2-x1
            H = y2-y1
            aspect_ratio = W / H
            return [aspect_ratio,W,H]
        except ZeroDivisionError:
            print("高度不能为0，无法计算宽高比。")

    def getAnglebypoint(self, point_1, point_2, point_3):
        """
        根据三点坐标计算夹角
        :param point_1: 点1坐标
        :param point_2: 点2坐标
        :param point_3: 点3坐标
        :return: 返回任意角的夹角值，这里只是返回点2的夹角
        """
        try:
            a = math.sqrt((point_2[0] - point_3[0]) * (point_2[0] - point_3[0]) + (point_2[1] - point_3[1]) * (
                        point_2[1] - point_3[1]))
            b = math.sqrt((point_1[0] - point_3[0]) * (point_1[0] - point_3[0]) + (point_1[1] - point_3[1]) * (
                        point_1[1] - point_3[1]))
            c = math.sqrt((point_1[0] - point_2[0]) * (point_1[0] - point_2[0]) + (point_1[1] - point_2[1]) * (
                        point_1[1] - point_2[1]))
            A = math.degrees(math.acos((a * a - b * b - c * c) / (-2 * b * c)))
            B = math.degrees(math.acos((b * b - a * a - c * c) / (-2 * a * c)))
            C = math.degrees(math.acos((c * c - a * a - b * b) / (-2 * a * b)))
            return [A,B,C]
        except :
            return [0, 0, 0]



def test():
    detector = nn.YOLOv8(model="/root/models/yolov8n_pose.mud")
    cam = camera.Camera(224,224, detector.input_format())
    dis = display.Display()
    pose_detector=Pose_Detector()
    while not app.need_exit():
        t = time.time_ms()
        img = cam.read()
        objs = detector.detect(img, conf_th = 0.5, iou_th = 0.45, keypoint_th = 0.5)
        for obj in objs:
            img.draw_rect(obj.x, obj.y, obj.w, obj.h, color = image.COLOR_RED)
            msg = f'{pose_detector.detect(obj)}: {obj.score:.2f}'
            img.draw_string(obj.x, obj.y, msg, color = image.COLOR_RED)
            pose_result=pose_detector.detect(obj)
            print(pose_result)
            detector.draw_pose(img, obj.points, 8 if detector.input_width() > 480 else 4, image.COLOR_RED)
        dis.show(img)

        print(f"time: {time.time_ms() - t}ms, fps: {1000 / (time.time_ms() - t)}")


if __name__ =="__main__":
    from rtmp_server import Rtmp_Server
    from mail import Email
    cam = camera.Camera(320, 240, image.Format.FMT_YVU420SP)
    dis = display.Display()
    rtmp_server=Rtmp_Server(cam=cam)
    email=Email()
    guarder=Guarder(mail=email,cam=cam,rtmp=rtmp_server,dis=dis)
    guarder.start()
    while not app.need_exit():
        guarder.run()


    