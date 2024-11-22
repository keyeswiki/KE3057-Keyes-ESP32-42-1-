from machine import Pin
import time

buzzer = Pin(13, Pin.OUT)
sensor = Pin(12, Pin.IN)
while True:
    buzzer.value(not(sensor.value()))
    time.sleep(0.01)