import time
from machine import Pin,PWM

#ESP32 PWM引脚输出的方式与传统控制器不同
#在初始化阶段通过配置PWM的参数，可以改变频率和占空比
#定义GPIO 5的输出频率为10000Hz，占空比为0，分配给PWM
pwm =PWM(Pin(5,Pin.OUT),10000)

try:
    while True: 
#占空比范围为0-1023，因此我们使用第一个for环来控制PWM以改变占空比
#周期值，使PWM输出0% -100%;使用第二个for环路使PWM输出100%-0%
        for i in range(0,1023):
            pwm.duty(i)
            time.sleep_ms(1)
            
        for i in range(0,1023):
            pwm.duty(1023-i)
            time.sleep_ms(1)  
except:
#每次使用PWM时，硬件定时器将打开以配合它。因此，每次使用PWM后
#需要调用deinit()来关闭计时器。否则会导致下次PWM工作失败
    pwm.deinit()