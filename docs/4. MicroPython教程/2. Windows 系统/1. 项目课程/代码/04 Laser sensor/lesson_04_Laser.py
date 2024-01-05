from machine import Pin
import time

laser = Pin(5, Pin.OUT)# 建立一个激光对象，将激光器连接到5号引脚，将5号引脚设置为输出模式
while True:
    laser.value(1) # 打开激光器
    time.sleep(2) # 延时2s
    laser.value(0) # 关掉激光
    time.sleep(2) # 延时2s