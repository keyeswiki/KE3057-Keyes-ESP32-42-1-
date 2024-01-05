import time
from rotary_irq_rp2 import RotaryIRQ
from machine import Pin, PWM

pwm_r = PWM(Pin(32)) 
pwm_g = PWM(Pin(4))
pwm_b = PWM(Pin(2))

pwm_r.freq(1000)
pwm_g.freq(1000)
pwm_b.freq(1000)

def light(red, green, blue):
    pwm_r.duty(red)
    pwm_g.duty(green)
    pwm_b.duty(blue)

SW=Pin(16,Pin.IN,Pin.PULL_UP)
r = RotaryIRQ(pin_num_clk=14,
              pin_num_dt=27,
              min_val=0,
              reverse=False,
              range_mode=RotaryIRQ.RANGE_UNBOUNDED)

while True:
    val = r.value()
    print(val%3)
    if val%3 == 0:
        light(1023, 0, 0)
    elif val%3 == 1:
        light(0, 1023, 0)
    elif val%3 == 2:
        light(0, 0, 1023)
    time.sleep(0.1)