/*  
 * 名称   : adjust the light
 * 功能   : 通过电位器控制LED的亮度
 * 作者   : http://www.keyes-robot.com/ 
*/
#define PIN_ANALOG_IN    34  //电位器的引脚
#define PIN_LED           5  // LED的引脚
#define CHANNEL           0  // 使用led通道0

void setup() {
  ledcSetup(CHANNEL, 1000, 12);     // PWM取值范围为0 ~ 4096
  ledcAttachPin(PIN_LED, CHANNEL);  // PIN_LED引脚定义为通道0的输出引脚
}

void loop() {
  ledcWrite(CHANNEL, analogRead(PIN_ANALOG_IN));   // 设置累计脉冲宽度
  delay(10);
}