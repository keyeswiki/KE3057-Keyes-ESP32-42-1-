from machine import Pin
import time

touch = Pin(5, Pin.IN, Pin.PULL_UP)

while True:
    if touch.value() == 1:
        print("You pressed the button!")   #按下打印相应信息
    else:
        print("You loosen the button!")
    time.sleep(0.1) #延迟0.1s
