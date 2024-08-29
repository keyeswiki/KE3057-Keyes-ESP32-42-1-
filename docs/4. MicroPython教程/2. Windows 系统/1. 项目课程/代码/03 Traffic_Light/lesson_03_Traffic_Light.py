import machine
import time 

led_red = machine.Pin(5, machine.Pin.OUT)
led_yellow = machine.Pin(13, machine.Pin.OUT)
led_green = machine.Pin(12, machine.Pin.OUT)

while True:
    led_green.value(1) # 绿灯亮
    time.sleep(5) # 延迟5 s
    led_green.value(0) # 绿灯关闭
    for i in range(3): #黄灯闪烁3次
        led_yellow.value(1)
        time.sleep(0.5)
        led_yellow.value(0)
        time.sleep(0.5)
    led_red.value(1) # 红灯亮
    time.sleep(5) # 延迟5 s
    led_red.value(0) #红灯关闭
