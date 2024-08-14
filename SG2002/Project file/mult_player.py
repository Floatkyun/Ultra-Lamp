import multiprocessing
from maix import audio, time,display,camera,image

class Mult_player:
    def __init__(self):
        self.process=None

    def thread_play(self,audio_file,sample_rate):
        print("play")
        player=audio.Player(sample_rate=sample_rate)
        with open(audio_file, 'rb') as f:
            ctx = f.read()
        player.play(bytes(ctx))
        t=len(ctx)*1000/sample_rate/2
        time.sleep_ms(int(t)+1)
        print("play end")
        return 

    def play(self,audio_file,sample_rate):
        self.process = multiprocessing.Process(target=self.thread_play,args=(audio_file,sample_rate,))
        self.process.daemon = True
        self.process.start() 

if __name__=="__main__":
    dis=display.Display()
    cam = camera.Camera(320, 240, image.Format.FMT_YVU420SP)
    mult_player=Mult_player()
    cam=None
    dis=None
    for i in range(10):
        dis=display.Display()
        cam = camera.Camera(320, 240, image.Format.FMT_YVU420SP)
        cam=None
        dis=None
        mult_player.play("/root/audio/drink/0.pcm",16000)
        mult_player.process.join()