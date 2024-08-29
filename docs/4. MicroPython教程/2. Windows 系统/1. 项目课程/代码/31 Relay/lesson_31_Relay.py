from machine import Pin
import time

# 创建继电器从引脚13，设置引脚13输出
relay = Pin(13, Pin.OUT)
 
# 继电器断开，继电器上COM和NO连接，COM和NC断开
def relay_on():
    relay(1)
 
# 继电器闭合，继电器上的COM和NO断开，COM和NC连接
def relay_off():
    relay(0)
 
# 循环，继电器开一秒关一秒
while True:
    relay_on()
    time.sleep(1)
    relay_off()
    time.sleep(1)
