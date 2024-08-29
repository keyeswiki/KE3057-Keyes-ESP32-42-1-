from machine import Pin
import time

button = Pin(5, Pin.IN, Pin.PULL_UP)

while True:
    if button.value() == 0:
        print("You pressed the button!")   #按下打印相应信息
    else:
        print("You loosen the button!")
    time.sleep(0.1) #延时0.1秒
