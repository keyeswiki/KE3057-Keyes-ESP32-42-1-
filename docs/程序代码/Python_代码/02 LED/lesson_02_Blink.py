from machine import Pin
import time

led = Pin(5, Pin.OUT)# 搭建一个LED对象，将外接LED灯连接到5号引脚，设置5号引脚为输出模式
while True:
    led.value(1)#打开灯
    time.sleep(1)# 延迟1s
    led.value(0)# 关闭灯
    time.sleep(1)# 延迟1s