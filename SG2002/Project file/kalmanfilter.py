class KalmanFilter:
    def __init__(self,LastP=0,Now_P=0,out=0,Kg=0,Q=0.2,R=15):
        #卡尔曼滤波初始化参数
        self.LastP=LastP#上次估算协方差
        self.Now_P=Now_P#当前估算协方差
        self.out=out#卡尔曼滤波器输出
        self.Kg=Kg#//卡尔曼增益
        self.Q=Q#过程噪声协方差
        self.R=R#观测噪声协方差
        self.state=0
    
    def re_init(self,LastP,Now_P,out,Kg,Q,R):
        self.LastP=LastP#上次估算协方差
        self.Now_P=Now_P#当前估算协方差
        self.out=out#卡尔曼滤波器输出
        self.Kg=Kg#//卡尔曼增益
        self.Q=Q#过程噪声协方差
        self.R=R#观测噪声协方差
        self.state=0

    def filt_con(self,mesureValue):#连续值滤波

        self.Now_P=self.LastP+self.Q

        self.Kg=self.Now_P/(self.Now_P+self.R)
        
        self.out=self.out+self.Kg*(mesureValue-self.out)

        self.LastP=(1-self.Kg)*self.Now_P
        
        return self.out

    def filt_dis(self,mesureValue):#离散值滤波

        self.Now_P=self.LastP+self.Q

        self.Kg=self.Now_P/(self.Now_P+self.R)

        self.out=self.out+self.Kg*(mesureValue-self.out)

        self.LastP=(1-self.Kg)*self.Now_P
        
        if self.state==0 and self.out>0.7:
            self.state=1
        elif self.state==1 and self.out<0.5:
            self.state=0
        return self.out