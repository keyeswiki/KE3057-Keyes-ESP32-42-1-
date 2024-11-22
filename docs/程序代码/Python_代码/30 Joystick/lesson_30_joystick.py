from machine import Pin, ADC
import time
#初始化摇杆模块(ADC功能)
rocker_x=ADC(Pin(34)) 
rocker_y=ADC(Pin(35))
button_z=Pin(13,Pin.IN,Pin.PULL_UP)

# 设置两个ADC通道的电压采集范围为0-3.3V，
# 并且采集的数据宽度为0-4095
rocker_x.atten(ADC.ATTN_11DB)
rocker_y.atten(ADC.ATTN_11DB)
rocker_x.width(ADC.WIDTH_12BIT)
rocker_y.width(ADC.WIDTH_12BIT)
 
# 在代码中，将Z_Pin配置为上拉输入模式
# 在loop()中，使用Read()读取X轴和Y轴的值
# 并使用value()读取Z轴的值，然后显示它们
while True:
    print("X,Y,Z:",rocker_x.read(),",",rocker_y.read(),",",button_z.value())
    time.sleep(0.5)