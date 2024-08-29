# 导入引脚和ADC模块
from machine import ADC,Pin
import time

# 开启并配置ADC，量程为0-3.3V
adc=ADC(Pin(34))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

# 电机的两个引脚
INA = Pin(5, Pin.OUT) # INA对应IN+
INB = Pin(13, Pin.OUT)# INB对应IN-

while True:
    adcVal=adc.read()
    print(adcVal)
    if adcVal < 3000:
        # 开启
        INA.value(0)
        INB.value(1)
    else:
        # 停止
        INA.value(0)
        INB.value(0)
    time.sleep(0.1)