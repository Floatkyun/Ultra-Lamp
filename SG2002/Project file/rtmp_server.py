from maix import camera, time, rtmp, image,display
import res

class Rtmp_Server:
    def __init__(self):
        self.host="120.27.132.21"
        self.port=10035
        self.app= 'live'
        self.stream = 'Ultra_Lamp'
        self.bitrate = 1000_000
        self.server= None
        self.www=None

    def start(self):
        self.cam=res.cam
        if self.cam!=None and self.cam.is_opened():
            self.server= rtmp.Rtmp(self.host, self.port, self.app, self.stream, self.bitrate)
            self.server.bind_camera(self.cam)
            print(self.server.start())
            self.www="http://120.27.132.21:10086/share.html?id=2&type=live&autoplay=yes&livetype=hls"
            print("rtmp://"+self.host+":"+str(self.port)+"/"+self.app+"/"+self.stream+"\nrtmp start!")
    
    def stop(self):
        self.cam=res.cam
        if self.server!=None and self.cam!=None and self.cam.is_opened():
            self.server.stop()
            self.server=None
            print("rtmp stop")


if __name__=="__main__":
    cam = camera.Camera(640, 480, image.Format.FMT_YVU420SP)
    rtmp_server=Rtmp_Server(cam=cam)

    rtmp_server.start()
    #cam2=cam.add_channel(320,320)
    while True:
        time.sleep(100)
        #t = time.time_ms()
        #img = cam2.read()
        #dis.show(img)
        #print(f"time: {time.time_ms() - t}ms, fps: {1000 / (time.time_ms() - t)}")