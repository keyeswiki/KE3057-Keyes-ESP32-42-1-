/*
 * 名称   : Breathing Led
 * 功能   : 让led灯像呼吸一样忽明忽暗。
 * 作者   : http//www.keyestudio.com
*/
const int PWM_LED_Pin = 5;  // LED 的 GPIO 引脚

void setup() 
{
  pinMode(PWM_LED_Pin, OUTPUT);  // 将 LED 引脚设置为输出模式
}

void loop() {
  for (int i = 0; i < 255; i++) 
  {  // 让灯光渐亮
    analogWrite(PWM_LED_Pin, i);   // 输出 PWM
    delay(10);                     // 延迟 10ms
  }
  for (int i = 255; i >= 0; i--) 
  {  // 让光线逐渐减弱消失
    analogWrite(PWM_LED_Pin, i);    // 输出 PWM
    delay(10);                      // 延迟 10ms
  }
}