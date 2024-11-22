/* 
 * 名称   : button_control_LED
 * 功能   : 做一盏台灯
 * 作者   : http://www.keyes-robot.com/ 
*/
#define PIN_LED    12
#define PIN_BUTTON 13
bool ledState = false;

void setup() {
// 初始化数字引脚PIN_LED作为输出
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
}

// 循环函数会一直运行下去
void loop() {
  if (digitalRead(PIN_BUTTON) == LOW) {
    delay(20);
    if (digitalRead(PIN_BUTTON) == LOW) {
      reverseGPIO(PIN_LED);
    }
    while (digitalRead(PIN_BUTTON) == LOW);
  }
}

void reverseGPIO(int pin) {
  ledState = !ledState;
  digitalWrite(pin, ledState);
}