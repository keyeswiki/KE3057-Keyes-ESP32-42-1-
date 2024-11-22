from machine import Pin
import time

sensor = Pin(5, Pin.IN, Pin.PULL_UP)
lastState = 0
PushCounter = 0

while True:
    State = sensor.value()
    if  State != lastState:
        if State == 1:
            PushCounter += 1
            print(PushCounter)   #按下打印相应信息
    lastState = State

