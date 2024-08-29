from machine import Pin
import time  

sensor = Pin(5, Pin.IN) 
while True:
    if sensor.value() == 0:
        print("There are obstacles")
    else:
        print("All going well")
    time.sleep(0.1)