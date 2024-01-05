# 导入引脚、ADC和DAC模块
from machine import ADC,Pin,DAC
import time

mq3_D = Pin(13, Pin.IN)
# 开启并配置ADC，量程为0-3.3V
adc=ADC(Pin(34))
adc.atten(ADC.ATTN_11DB) 
adc.width(ADC.WIDTH_12BIT)

# 每0.1秒读取一次数字值和ADC值，将ADC值转换为DAC值和电压值输出;
# 并将这些数据打印到“Shell”
while True:
    digitalVal = mq3_D.value()
    adcVal=adc.read()
    dacVal=adcVal//16
    voltage = adcVal / 4095.0 * 3.3
    print("digitalVal:",digitalVal,"ADC Val:",adcVal,"DACVal:",dacVal,"Voltage:",voltage,"V", end = "  ")
    if digitalVal == 0:
        print("Exceeding")
    else:
        print("Normal")
    time.sleep(0.1)
