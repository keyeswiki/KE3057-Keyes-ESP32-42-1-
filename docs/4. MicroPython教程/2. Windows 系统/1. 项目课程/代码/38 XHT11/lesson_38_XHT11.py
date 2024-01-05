# 导入机器、时间和dht模块
import machine
import time
import dht

#将DHT11与引脚(15)关联
DHT = dht.DHT11(machine.Pin(13))

# 每秒获取1次温湿度数据并打印
while True:
    DHT.measure() # 启动DHT11测量一次数据
   # 调用DHT的内置函数来获取温度和湿度数据，并打印在“Shell”中
    print('temperature:',DHT.temperature(),'℃','humidity:',DHT.humidity(),'%')
    time.sleep_ms(1000)