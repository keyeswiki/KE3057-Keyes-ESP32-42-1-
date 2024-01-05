#导入引脚和时间模块
from machine import Pin 
import time 

# 定义人体红外传感器，led和主动蜂鸣器的引脚
sensor_pir = Pin(12, Pin.IN)
led = Pin(5, Pin.OUT)
buzzer = Pin(13, Pin.OUT)

while True: 
      if sensor_pir.value():
          print("Warning! Intrusion detected！")
          buzzer.value(1)
          led.value(1)
          time.sleep(0.2)
          buzzer.value(0)
          led.value(0)
          time.sleep(0.2)         
      else:
          buzzer.value(0)
          led.value(0)
