from machine import Pin
import time

led = Pin(12, Pin.OUT) # 从引脚12创建LED对象，设置引脚12输出             
button = Pin(13, Pin.IN, Pin.PULL_UP) #从GP13创建按钮对象，设置GP13为输入

#自定义一个函数并将其命名为reverseGPIO()，它将反转LED的输出电平
def reverseGPIO():
    if led.value():
        led.value(0)     #设置led关闭
    else:
        led.value(1)     #设置led开启

try:
    while True:
        if not button.value():
            time.sleep_ms(20)
            if not button.value():
                reverseGPIO()
                while not button.value():
                    time.sleep_ms(20)
except:
    pass
