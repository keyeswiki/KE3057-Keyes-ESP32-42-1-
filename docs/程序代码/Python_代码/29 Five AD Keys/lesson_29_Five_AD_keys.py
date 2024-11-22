# 导入引脚和ADC模块
from machine import ADC,Pin
import time 

# 开启并配置ADC，量程为0-3.3V
adc=ADC(Pin(34))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

while True:
    adcvalue = adc.read() 
    print(adcvalue, end = '')
    if adcvalue <= 500:
        print("  no key  is pressed")
    elif adcvalue <= 1000:
        print("  SW5 is pressed")
    elif adcvalue <= 2000:
        print("  SW4 is pressed")
    elif adcvalue <= 3000:
        print("  SW3 is pressed")
    elif adcvalue <= 4000:
        print("  SW2 is pressed")
    else:
        print("  SW1 is pressed")
    time.sleep(0.5)