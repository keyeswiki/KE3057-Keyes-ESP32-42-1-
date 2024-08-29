from machine import Pin, ADC
import time
import math

#Set ADC
adc=ADC(Pin(34))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

try: 
    while True:
        adcValue = adc.read()
        voltage = adcValue / 4096 * 3.3
        Rt =(3.3-voltage) / voltage * 4700
        tempK = (1 / (1 / (273.15+25) + (math.log(Rt/10000)) / 3950))
        tempC = (tempK - 273.15)+0.5
        print("ADC value:",adcValue,"  Voltage:",voltage,"V","  Temperature: ",tempC,"C");
        time.sleep(1)
except:
    pass