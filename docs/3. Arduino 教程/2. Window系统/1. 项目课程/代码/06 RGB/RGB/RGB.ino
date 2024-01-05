/*
 * 名称   : RGB LED
 * 功能   : 使用RGBLED显示随机颜色
 * 作者   : http://www.keyes-robot.com/ 
*/
int ledPins[] = {32, 4, 2};           //定义红色，绿色，蓝色引脚
const byte chns[] = {0, 1, 2};        //定义PWM通道
int red, green, blue;
void setup() {
  for (int i = 0; i < 3; i++) {       //设置pwm通道，1KHz，8bit
    ledcSetup(chns[i], 1000, 8);
    ledcAttachPin(ledPins[i], chns[i]);
  }
}

void loop() {
  red = random(0, 256);
  green = random(0, 256);
  blue = random(0, 256);
  setColor(red, green, blue);
  delay(200);
}

void setColor(byte r, byte g, byte b) {
  ledcWrite(chns[0], 255 - r);       //共阴LED，低电平打开LED。
  ledcWrite(chns[1], 255 - g);
  ledcWrite(chns[2], 255 - b);
}