/*  
 * 名称   : Photoresistance
 * 功能   : 将光敏电阻的阻值转换成ADC,DAC和电压值
 * 作者   : http://www.keyes-robot.com/ 
*/
#define PIN_ANALOG_IN  34  //光敏电阻的引脚

void setup() {
  Serial.begin(9600);
}

//在loop()中，使用analogRead()函数获取ADC值，
//然后使用map()函数将该值转换为8位精度DAC值。
//输入输出电压按下面公式计算，
//将信息打印出来
void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);
  int dacVal = map(adcVal, 0, 4095, 0, 255);
  double voltage = adcVal / 4095.0 * 3.3;
  Serial.printf("ADC Val: %d, \t DAC Val: %d, \t Voltage: %.2fV\n", adcVal, dacVal, voltage);
  delay(200);
}