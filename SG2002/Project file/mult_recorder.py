import multiprocessing
from maix import audio, time

class Mult_recorder:
    def __init__(self):
        self.process=None

    def thread_record(self,audio_file,sample_rate):
        print("play")
        recorder=audio.Recorder(sample_rate=16000)#录音麦克风
        recorder.volume(24)
        with open(audio_file, 'rb') as f:
            ctx = f.read()
        player.play(bytes(ctx))
        t=len(ctx)*1000/sample_rate/2
        time.sleep_ms(int(t)+1)
        print("play end")
        return 

    def record(self,audio_file,sample_rate):
        self.process = multiprocessing.Process(target=self.thread_play,args=(audio_file,sample_rate,))
        self.process.daemon = True
        self.process.start() 

if __name__=="__main__":
    mult_recorder=Mult_recorder()
    for i in range(10):
        pass


