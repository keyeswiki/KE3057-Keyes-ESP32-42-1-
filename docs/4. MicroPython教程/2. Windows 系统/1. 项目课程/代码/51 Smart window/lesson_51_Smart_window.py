# 导入引脚和ADC模块
from machine import ADC,Pin,PWM
import time 

# 开启并配置ADC，量程为0-3.3V
adc=ADC(Pin(34))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

pwm = PWM(Pin(4))#转向销连接到GP4
pwm.freq(50)#20ms周期，所以频率为50Hz
'''
占空比对应的角度
0°----2.5%----25
45°----5%----51.2
90°----7.5%----77
135°----10%----102.4
180°----12.5%----128
考虑到误差，占空比设为1000~9000，可平稳旋转0~180度
'''
angle_0 = 25
angle_90 = 77
angle_180 = 128
    
while True:
    adcVal=adc.read()
    print(adcVal)
    if adcVal > 2000:
        pwm.duty(angle_0)
        time.sleep(0.5)
    else:
        pwm.duty(angle_180)
        time.sleep(0.5)