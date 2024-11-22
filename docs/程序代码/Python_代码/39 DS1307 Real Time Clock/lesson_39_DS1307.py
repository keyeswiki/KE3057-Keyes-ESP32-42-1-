from machine import I2C, Pin
import time

# 配置I2C总线
i2c = I2C(scl=Pin(22), sda=Pin(21), freq=400000)
#DS1307写入时间已启用
year0 = int(input("Year : "))
month0 = int(input("month (Jan --> 1 , Dec --> 12): "))
day0 = int(input("day : "))
weekday0 = int(input("weekday (1 --> monday , 2 --> Tuesday ... 0 --> Sunday): "))
hours0 = int(input("hour (24 Hour format): "))
minutes0 = int(input("minute : "))
seconds0 = int(input("second : "))
seconds = ((seconds0 // 10) << 4) + (seconds0 % 10)
minutes = ((minutes0 // 10) << 4) + (minutes0 % 10)
hours = ((hours0 // 10) << 4) + (hours0 % 10)
weekday = weekday0 % 7 
day = ((day0 // 10) << 4) + (day0 % 10)
month = ((month0 // 10) << 4) + (month0 % 10)
year = ((year0 - 2000) // 10 << 4) + (year0 - 2000) % 10
#将时间写入DS1307
i2c.writeto_mem(0x68, 0x00, bytes([seconds, minutes, hours, weekday, day, month, year]))

while True:   
    # 发送命令读取当前时间
    i2c.writeto(0x68, bytes([0x00]))

    # 从DS1307读取当前时间
    data = i2c.readfrom(0x68, 7)
    seconds = (data[0] & 0x0f) + ((data[0] & 0x70) >> 4) * 10
    minutes = (data[1] & 0x0f) + ((data[1] & 0x70) >> 4) * 10
    hours = (data[2] & 0x0f) + (((data[2] & 0x30) >> 4) % 2) * 10
    weekday = data[3]
    day = (data[4] & 0x0f) + ((data[4] & 0x30) >> 4) * 10
    month = (data[5] & 0x0f) + ((data[5] & 0x10) >> 4) * 10
    year = (data[6] & 0x0f) + ((data[6] & 0xf0) >> 4) * 10
    print('20{:02}/{:02}/{:02} {:02}:{:02}:{:02} {:2}'.format(year, month, day, hours, minutes, seconds,weekday))
    time.sleep(1)                   
