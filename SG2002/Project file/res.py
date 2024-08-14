from maix import camera, display, image, nn, app, time,audio

cam=None
dis=None

def res_init():
    global cam,dis
    cam=camera.Camera(320, 240, image.Format.FMT_YVU420SP)
    dis=display.Display()

def res_distroy():
    global cam,dis
    cam=None
    dis=None