from maix import camera, image
import smtplib
import email.utils
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.image import MIMEImage

class Email():
    def __init__(self):
        self.server = smtplib.SMTP_SSL(host='smtp.qq.com',port=465)
        self.server.login('923306870@qq.com','yyoxkrfkhgyjbdbg')
        print("login success!")

    def save_img(self,img):
        temp_img_path="/root/temp_img/temp_img.jpeg"
        img.save(temp_img_path)
        return temp_img_path

    def send(self,text="UltraLamp检查到有人经过",url='"http://120.27.132.21:10086/share.html?id=1&type=live&autoplay=yes&livetype=hls"',urldis="点击查看UltraLamp的周边状况",subject='【守卫模式】UltraLamp检查到有人经过',img=None):
        message = MIMEMultipart("related")
        message['To'] = email.utils.formataddr(('用户', '923306870@qq.com'))
        message['From'] = email.utils.formataddr(('Ultra_Lamp', '923306870@qq.com'))
        message['Subject'] = subject
        mail_content = f"亲爱的用户:<p>{text}</p> <p><a href={url}>{urldis}</a></p>"
        if img!=None:
            pic_file=self.save_img(img)
            with open(pic_file,'rb') as image:
                image_info = MIMEImage(image.read())
                image_info.add_header('Content-Id',f'<image{1}>')
                message.attach(image_info)
                pic_inline =f'''
                    <!-- <br>这是一段对图片进行描述的文本 {pic_file}:</br> -->
                    <br><img src="cid:image{1}" width="300" alt={pic_file}></br>
                    '''      
        body_footer = '<p style="color:red">此邮件为Ultra_Lamp发送，请勿在此邮件上直接回复，谢谢~~</p>'
        #message.attach(MIMEText(mail_content,'html'))
        if img!=None:
            message.attach(MIMEText(mail_content + pic_inline + body_footer, "html", "utf-8"))
        else:
            message.attach(MIMEText(mail_content + body_footer, "html", "utf-8"))
        try:
            self.server.sendmail('923306870@qq.com',['923306870@qq.com'],msg=message.as_string())
            
            return True
        except:
            print("failed")
            return False
        
    def close(self):
        self.server.quit()

if __name__=="__main__":
    
    img_width=640
    img_height=480
    cam = camera.Camera(320,240, image.Format.FMT_YVU420SP)

    cam2 = cam.add_channel(img_width, img_height)
        
    cam2.skip_frames(120)
    EMAIL=Email()
    img = cam2.read()
    EMAIL.send(img=img)

    EMAIL.close()