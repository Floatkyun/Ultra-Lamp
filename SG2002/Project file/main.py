from maix import camera, display, image, nn, app, time,audio
from work_detector import WorkDetector
from rtsp_server import Rtsp_Server
from rtmp_server import Rtmp_Server
from hand_tracker import Hand_Tracker
from uartserial import UartSerial_ToSTM32
from mqtt import Mqtt_device,mqtt_init
import mqtt
from mail import Email
from util import show_detect_result
from guarder import Guarder
from audio_warn import Audio_Warn
from chatglm4v import ChatGLM4V
import res

if __name__=="__main__":
    audio_warn=Audio_Warn()
    chat_glm4v=ChatGLM4V()
    ###sys_init
    img_width=320
    img_height=320

    res.res_init()
    rtmp_server=Rtmp_Server()
    email=Email()

    uart_serial=UartSerial_ToSTM32(audio_warn=audio_warn,chat_glm4v=chat_glm4v,email=email,rtmp=rtmp_server)
    
    
    mqtt_device=mqtt_init(Uartserial=uart_serial,rtmp_server=rtmp_server)
    uart_serial.bind_mqtt(mqtt_device) 

    #uart_serial.time_cali()
    
    ###main_loop
    #def main_loop1():
        #while not app.need_exit():
            #t = time.time_ms()
            #img = cam2.read()
            #objs = detector.detect(img, conf_th = 0.6, iou_th = 0.45)
            #hands=hand_detector.detect(img, conf_th = 0.5, iou_th = 0.45)
            
            #work_name = work_detector.work_name(work_detector.current_work(objs,hands))
            #hand_tracker.track_hands(hands)

            #img=show_detect_result(show_detect_result(img,detector,objs),hand_detector,hands)
            #img.draw_string(0, 0, work_name, color = image.COLOR_RED)
            
            #print(work_name)
            #dis.show(img)
            #print(f"time: {time.time_ms() - t}ms, fps: {1000 / (time.time_ms() - t)}")
    def main_loop2():
        while not app.need_exit():
            #uart_serial.uart_A.write(bytes("msg", encoding='utf-8'))
            uart_serial.deal_input()
            #print(cam.is_opened())
            uart_serial.run()
            time.sleep_ms(1)
    #def main_loop3():
        #work_detector.run_statistics_analyser()
        #print("stopping")
        #t = time.time_ms()
        #work_detector.stop_statistics_analyser()
        #t = time.time_ms()-t
        #print("stopped:",t,"ms")
        #work_detector.run_statistics_analyser()
        #print("stopping")
        #t = time.time_ms()
        #work_detector.stop_statistics_analyser()
        #t = time.time_ms()-t
        #print("stopped:",t,"ms")
        #while not app.need_exit():
            #t = time.time_ms()
            #img = cam2.read()
            #objs = detector.detect(img, conf_th = 0.6, iou_th = 0.45)
            #hands=hand_detector.detect(img, conf_th = 0.5, iou_th = 0.45)
            
            #work_name = work_detector.work_name(work_detector.current_work(objs,hands))

            #img=show_detect_result(show_detect_result(img,detector,objs),hand_detector,hands)
            #print(work_name)
            #dis.show(img)
            #print(f"time: {time.time_ms() - t}ms, fps: {1000 / (time.time_ms() - t)}")

    def main_loop4():
        uart_serial.init_work_detector_hand_tracker(img_width, img_height)
        while not app.need_exit():
            t = time.time_ms()
            uart_serial.run_work_detector_hand_tracker()
            uart_serial.deal_input()
            #uart_serial.run()
            print(f"time: {time.time_ms() - t}ms, fps: {1000 / (time.time_ms() - t)}")
        uart_serial.destroy_work_detector_hand_tracker()
    
    def guarder_loop():
        guarder=Guarder(mail=email,cam=res.cam,rtmp=rtmp_server,dis=res.dis)
        guarder.start()
        while not app.need_exit():
            guarder.run()


    main_loop2()
    #work_detector.stop_statistics_analyser()
    