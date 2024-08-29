from machine import Pin
import time

CollisionSensor = Pin(5, Pin.IN)

while True:
    value = CollisionSensor.value()
    print(value, end = " ")
    if  value== 0:
        print("The end of this!")
    else:
        print("All going well")
    time.sleep(0.1)