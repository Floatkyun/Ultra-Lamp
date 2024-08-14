import requests
from datetime import datetime
import pytz
 
def get_utc_time():
    try:
        # 发送请求到网络时间服务器
        response = requests.get("http://worldtimeapi.org/api/timezone/Etc/UTC")
        response.raise_for_status()  # 检查请求是否成功
 
        # 解析响应的 JSON 数据
        time_data = response.json()
        
        # 获取并返回网络时间
        return datetime.fromisoformat(time_data['utc_datetime'])
    except Exception as e:
        print(f"获取网络时间失败：{e}")
        return None
 
def get_target_timezone_time(target_timezone):
    flag=0
    while flag<5:
        try:
            # 获取网络时间
            utc_time = get_utc_time()
     
            if utc_time:
                # 定义目标时区
                target_timezone_obj = pytz.timezone(target_timezone)
     
                # 将网络时间转换为目标时区时间
                target_time = utc_time.astimezone(target_timezone_obj)
                return target_time
            else:
                flag+=1
                print("retry")
        except Exception as e:
            print(f"转换时区失败：{e}")
    return datetime.now()

def get_time_str():
    beijing_time = get_target_timezone_time('Asia/Shanghai')
    second=beijing_time.second
    minute=beijing_time.minute
    hour=beijing_time.hour 
    
    time_str=(f"t%2d:%2d:%2d"%(hour,minute,second)).replace(" ","0")
    time_str=time_str+"00"
    print(time_str)
    return time_str
# 示例：获取美国纽约时区时间
#"t11:22:33\n"
if __name__=="__main__":
    print( get_time_str())