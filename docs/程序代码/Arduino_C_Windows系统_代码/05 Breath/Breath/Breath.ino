/*
 * 名称   : Breathing Led
 * 功能   : 让led灯像呼吸一样忽明忽暗。
 * 作者   : http//www.keyes-robot.com
*/
#define PIN_LED   5     //定义led引脚
#define CHN       0     //定义PWM通道
#define FRQ       1000  //定义PWM频率
#define PWM_BIT   8     //定义PWM精度
void setup() {
  ledcSetup(CHN, FRQ, PWM_BIT); //设置PWM通道
  ledcAttachPin(PIN_LED, CHN);  //将led引脚连接到PWM通道
}

void loop() {
  for (int i = 0; i < 255; i++) {   //使灯光渐显
    ledcWrite(CHN, i);
    delay(10);
  }
  for (int i = 255; i > -1; i--) {  //使灯光渐隐
    ledcWrite(CHN, i);
    delay(10);
  }
}
