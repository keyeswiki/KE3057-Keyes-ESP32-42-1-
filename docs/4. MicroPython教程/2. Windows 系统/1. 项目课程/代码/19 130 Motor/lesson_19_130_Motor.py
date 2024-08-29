from machine import Pin
import time

#电机的两个引脚
INA = Pin(5, Pin.OUT) #INA corresponds to IN+
INB = Pin(13, Pin.OUT)#INB corresponds to IN- 

while True:
    #逆时针方向 2s
    INA.value(1)
    INB.value(0)
    time.sleep(2)
    #停止 1s
    INA.value(0)
    INB.value(0)
    time.sleep(1)
    #顺时针旋转 2s
    INA.value(0)
    INB.value(1)
    time.sleep(2)
    #停止 1s
    INA.value(0)
    INB.value(0)
    time.sleep(1)