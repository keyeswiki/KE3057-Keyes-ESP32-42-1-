from machine import Pin
import time

sensor = Pin(5, Pin.IN, Pin.PULL_UP)

while True:
    if sensor.value() == 0:
        print("0   White")   #按下打印相应信息
    else:
        print("1   Black")
    time.sleep(0.1) #延时 0.1s
