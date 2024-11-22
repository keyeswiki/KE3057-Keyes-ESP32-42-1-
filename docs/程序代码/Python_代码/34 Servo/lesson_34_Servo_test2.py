from utime import sleep
from machine import Pin
from machine import PWM

pwm = PWM(Pin(4))#舵机销连接GP4
pwm.freq(50)#20ms周期，所以频率为50Hz
'''
Duty cycle corresponding to the Angle
0°----2.5%----25
45°----5%----51.2
90°----7.5%----77
135°----10%----102.4
180°----12.5%----128
'''
# 设置伺服旋转角度
def setServoCycle (position):
    pwm.duty(position)
    sleep(0.01)

# 将旋转角度转换为占空比
def convert(x, i_m, i_M, o_m, o_M):
    return max(min(o_M, (x - i_m) * (o_M - o_m) // (i_M - i_m) + o_m), o_m)

while True:
    for degree in range(0, 180, 1):#伺服电机从0到180
        pos = convert(degree, 0, 180, 20, 150)
        setServoCycle(pos)

    for degree in range(180, 0, -1):#伺服电机从180到0
        pos = convert(degree, 0, 180, 20, 150)
        setServoCycle(pos)
