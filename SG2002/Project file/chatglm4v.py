import requests,os,json,base64
from maix import display, image,audio,touchscreen,app,camera,time
import multiprocessing

class ChatGLM4V():
    def __init__(self):
        self.started=False
        self.is_recording=multiprocessing.Value('b', False)
        self.recordprocess=None
        #ASR初始化
        self.AUDIO_FILE = '/root/output.pcm'
        self.AUDIO_RESPONCE_FILE = '/root/responce.pcm'
        self.RATE = 16000
        self.ASR_URL = 'http://vop.baidu.com/server_api'
        self.quest=None
        self.rec=None
        self.t=0       
                                       
        self.API_KEY='uh5eqtmLsZNrR2h7irMNyhdx'
        self.SECRET_KEY='qYfvo0bgAHTXfUeWcXON1NR2XeQ3jCOM'
        TOKEN_URL = 'http://aip.baidubce.com/oauth/2.0/token'
        FORMAT = self.AUDIO_FILE[-3:]
        CUID = 'maixcam000907898989'
        DEV_PID = 1537
        post_data = {
        'grant_type': 'client_credentials',
        'client_id': self.API_KEY,
        'client_secret': self.SECRET_KEY
        }
        
        response = requests.post(TOKEN_URL, data=post_data)
        result = response.json()
        #print(result)
        #print('ASR初始化:成功获取令牌: %s ; 有效期秒数: %s' % (result['access_token'], result['expires_in']))

        token=result['access_token']
        print(token)
        params = {'cuid': CUID, 'token': token, 'dev_pid': DEV_PID}
        self.key = '&'.join([f"{key}={value}" for key, value in params.items()])
        self.headers = {
        'Content-Type': 'audio/' + FORMAT + '; rate=' + str(self.RATE),
        'Accept': 'application/json'
        }

    def ASR(self):
        audio_file_size = os.path.getsize(self.AUDIO_FILE)
        self.headers['Content-Length'] = str(audio_file_size)
        with open(self.AUDIO_FILE, 'rb') as speech_file:
            speech_data = speech_file.read()
        response = requests.post(f"{self.ASR_URL}?{self.key}", headers=self.headers, data=speech_data)
        try:
            result_dict = response.json()
            a = result_dict['result'][0]
            print(a)  
            self.quest= a
            return a
        except :
            a = "响应不是有效的JSON:" + response.text
            print(a)
            return "ERROR"
    

    def Chat(self):
        url = 'https://open.bigmodel.cn/api/paas/v4/chat/completions'
        headers = {
            'Authorization': '03588d78a60cb85da41642599ce6eaae.0DC7ORnrEjKEpgNy',
            'Content-Type': 'application/json'
        }
        data = {
            "model": "glm-4-0520",
            "messages": [
                {
                    "role": "user",
                    "content": f"{self.quest}"
                }
            ]
        }

        response = requests.post(url, headers=headers, data=json.dumps(data))

        rec = response.json()
        print(rec)
        rec = rec['choices'][0]['message']['content']
        self.rec=rec
        print(rec)
        return rec

    def record(self):
        recorder=audio.Recorder(sample_rate=16000)#录音麦克风
        recorder.volume(24)
        if os.path.exists(self.AUDIO_FILE):
                os.remove(self.AUDIO_FILE)
        with open(self.AUDIO_FILE, "ab") as f:
            while self.is_recording.value:
                data = recorder.record()
                f.write(data)
            recorder.finish()

    def run_recorder(self):
        if self.recordprocess ==None:
            self.recordprocess = multiprocessing.Process(target=self.record,args=())
            self.recordprocess.daemon = True
            self.is_recording.value=True
            self.recordprocess.start()
    
    def stop_recorder(self):
        if self.recordprocess !=None:
            self.is_recording.value=False
            self.recordprocess.join()
            self.recordprocess=None

    def speech_gen(self):
        txt=str(self.rec.encode('utf-8')).replace("\\x","%")[1:]
        tocken_url = "https://aip.baidubce.com/oauth/2.0/token"
        params = {"grant_type": "client_credentials", "client_id": self.API_KEY, "client_secret": self.SECRET_KEY}
        access_token= str(requests.post(tocken_url, params=params).json().get("access_token"))
        
        url = "https://tsn.baidu.com/text2audio"
        payload=f'tex={txt}&tok='+ access_token +'&cuid=i7KqSZDSewxPl0HpRsAmKARCQ8Ov3L1C&ctp=1&lan=zh&spd=5&pit=5&vol=15&per=5118&aue=4'
        headers = {
            'Content-Type': 'application/x-www-form-urlencoded',
            'Accept': '*/*'
        }
        
        response = requests.request("POST", url, headers=headers, data=payload)
        with open(self.AUDIO_RESPONCE_FILE,'wb') as f:
            f.write(response.content)

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

    def play_speech_gen(self):
        print("play_speech_gen")
        self.run_play(self.AUDIO_RESPONCE_FILE,16000)
        #with open(self.AUDIO_RESPONCE_FILE, 'rb') as f:
            #ctx = f.read()
        #self.player.play(bytes(ctx))

        #return len(ctx)*1000/16000/2
    
    def start(self):
        self.started=True
        self.t=time.time()
        #print(self.t)
        self.run_recorder()
        print("run_recorder")
    
    def stop(self):
        while time.time()-self.t<2:
            time.sleep_ms(1)
        self.started=False
        self.stop_recorder()
        print("stop_recorder")
        self.ASR()
        self.Chat()
        self.speech_gen() 
        self.play_speech_gen()       

if __name__=="__main__":
    #recorder=audio.Recorder(sample_rate=16000)#录音麦克风
    #recorder.volume(24)
    #player= audio.Player(sample_rate=16000)
    #cam = camera.Camera(320, 240, image.Format.FMT_YVU420SP)
    chat=ChatGLM4V()
    #cam = camera.Camera(320, 240, image.Format.FMT_YVU420SP)
    
    chat.start()
    print("start")
    time.sleep(3)
    chat.stop()
    while not app.need_exit():
        time.sleep(1)

    






    

