from maix import app, rtsp, camera, image, display

# init rtsp server
class Rtsp_Server:
    def __init__(self,cam,ip="10.171.27.1"):
        self.server = rtsp.Rtsp(ip=ip)
        #self.server = rtsp.Rtsp()
        self.server.bind_camera(cam)
        self.rgn = None
        self.canvas = None

    def rtsp_start(self):
        self.server.start()
        print(self.server.get_url())


    def rtsp_stop(self):
        self.rgn = None
        self.canvas = None
        self.rgn = self.server.add_region(0, 0,320,180)
        self.canvas = self.rgn.get_canvas()
        self.canvas =self.canvas.clear().invert().draw_string(10, 90, "RTSP",scale=3,color=image.Color.from_rgb(255,0,0),thickness=3).draw_string(10, 90+40, "STOPPED",scale=3,color=image.Color.from_rgb(255,0,0),thickness=3)
        self.rgn.update_canvas()

    def rtsp_continue(self):
        self.rgn = None
        self.canvas = None
        self.rgn = self.server.add_region(0, 0,320,180)
        self.canvas = self.rgn.get_canvas()
        self.canvas =self.canvas.clear()
        self.rgn.update_canvas()

if __name__=="__main__":
    cam = camera.Camera(320,180, image.Format.FMT_YVU420SP)
    cam2 = cam.add_channel(640, 480)

    rtsp_server=Rtsp_Server(cam)
    rtsp_server.rtsp_start()
    rtsp_server.rtsp_stop()


    # init display
    disp = display.Display()
    i=0
    while not app.need_exit():
        i+=1
        img = cam2.read()
        disp.show(img)
        if i==60:
            rtsp_server.rtsp_continue()

        elif i==120:
            rtsp_server.rtsp_stop()
            i=0
    
    rtsp_server.rtsp_start()