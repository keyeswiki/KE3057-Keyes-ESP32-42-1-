from machine import ADC, Pin, PWM
import time
import machine
import random

pwm_r = PWM(Pin(2))
pwm_g = PWM(Pin(4))
pwm_b = PWM(Pin(32))

pwm_r.freq(1000)
pwm_g.freq(1000)
pwm_b.freq(1000)

potentiometer_adc=ADC(Pin(35))
potentiometer_adc.atten(ADC.ATTN_11DB)
potentiometer_adc.width(ADC.WIDTH_10BIT)

button = Pin(23, Pin.IN)
led = PWM(Pin(5,Pin.OUT),1000)

Avoiding = Pin(14, Pin.IN, Pin.PULL_UP) 

button_z=Pin(18,Pin.IN,Pin.PULL_UP)
rocker_x=ADC(Pin(33))
rocker_y=ADC(Pin(34))
rocker_x.atten(ADC.ATTN_11DB)
rocker_y.atten(ADC.ATTN_11DB)
rocker_x.width(ADC.WIDTH_10BIT)
rocker_y.width(ADC.WIDTH_10BIT)

# 设置超声波引脚
trigger = Pin(13, Pin.OUT)
echo = Pin(12, Pin.IN)

def light(red, green, blue):
    pwm_r.duty(red)
    pwm_g.duty(green)
    pwm_b.duty(blue)

# 超声波测距，单位:厘米
def getDistance(trigger, echo):
    # 产生10us方波
    trigger.value(0)   #事先给一个短的低电平，以确保一个干净的高脉冲;
    time.sleep_us(2)
    trigger.value(1)
    time.sleep_us(10)#拉高后，等待10微秒，立即调低
    trigger.value(0)
    
    while echo.value() == 0: #建立while循环，检测回波引脚值是否为0，并记录此时的时间
        start = time.ticks_us()
    while echo.value() == 1: #建立while循环，检查回波引脚值是否为1，并记录此时的时间
        end = time.ticks_us()
    d = (end - start) * 0.0343 / 2 #声波的传播时间x声速(343.2 m/s, 0.0343 cm/微秒)，再除以来回距离2
    return d


keys = 0
nums = 0
print(keys % 5)
def toggle_handle(pin):
    global keys
    keys += 1
    print(keys % 4)

button.irq(trigger = Pin.IRQ_FALLING, handler = toggle_handle)

def showRGB():
    R = random.randint(0,1023)
    G = random.randint(0,1023)
    B = random.randint(0,1023)
    light(R, G, B)
    time.sleep(0.3)

def showAvoiding():
    if Avoiding.value() == 0:
        print("0   There are obstacles")   #按下打印相应信息
    else:
        print("1   All going well")
    time.sleep(0.1) #延时0.1秒
    
def showJoystick():
    B_value = button_z.value()
    X_value = rocker_x.read()
    Y_value = rocker_y.read()
    print("button:", end = " ")
    print(B_value, end = " ")
    print("X:", end = " ") 
    print(X_value, end = " ")
    print("Y:", end = " ")
    print(Y_value)
    time.sleep(0.1)

def adjustLight():
    pot_value = potentiometer_adc.read()
    led.duty(pot_value)
    print(pot_value)
    time.sleep(0.1)

def showDistance():
    distance = getDistance(trigger, echo)
    print("The distance is ：{:.2f} cm".format(distance))
    time.sleep(0.1)

while True:
    nums = keys % 5  #按键次数对5取模得到0,1,2,3,4
    if nums == 0:  #根据RGB
        showRGB() 
    elif nums == 1:  #显示避让传感器的高低电平
        showAvoiding() 
    elif nums == 2: #显示摇杆值
        showJoystick()
    elif nums == 3:  #电位器调节LED
        adjustLight()
    elif nums == 4:  #显示超声波测距值
        showDistance()