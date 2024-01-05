from machine import Pin
import time

buzzer = Pin(5, Pin.OUT)
sensor = Pin(13, Pin.IN)
 
while True:
    Val = sensor.value()
    print(Val)
    if Val == 0:
        buzzer.value(1)
    else:
        buzzer.value(0)
    time.sleep(0.5)