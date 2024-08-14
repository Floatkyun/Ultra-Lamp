from maix import audio, time, app
from glob import  glob
import random
import multiprocessing

class Audio_Warn:
    def __init__(self,path="/root/audio/"):
        self.game_audio_files=glob("/root/audio/game/*.pcm")
        self.drink_audio_files=glob("/root/audio/drink/*.pcm")
        self.work_audio_files=glob("/root/audio/work/*.pcm")

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

    def run_play(self,audio_file,sample_rate):
        self.process = multiprocessing.Process(target=self.thread_play,args=(audio_file,sample_rate,))
        self.process.daemon = True
        self.process.start() 

    def play(self,kind="game"):
        target_files=None
        rand_int=random.randint(0,100)
        if kind=="game":
            rand_int=rand_int%len(self.game_audio_files)
            target_files=self.game_audio_files
        elif kind=="drink":
            rand_int=rand_int%len(self.drink_audio_files)
            target_files=self.drink_audio_files
        elif kind=="work":
            rand_int=rand_int%len(self.work_audio_files)
            target_files=self.work_audio_files
        else:
            return 0

        self.run_play(target_files[rand_int],16000)
        #with open(target_files[rand_int], 'rb') as f:
            #ctx = f.read()

        #print("ready play warning")
        #self.player.play(bytes(ctx))
        #print("playing warning")
        #return len(ctx)*1000/16000/2 #return the time of audio in ms
        


if __name__=="__main__":
    audio_warn=Audio_Warn()
    while True:
        print("runing")
        audio_warn.play("work")
        time.sleep(10)
        #time.sleep_ms(int(audio_warn.play("work"))+1)


