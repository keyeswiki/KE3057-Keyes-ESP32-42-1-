/*  
 * 名称   : Film pressure sensor
 * 功能   : 将薄膜压力传感器感受到的压力值转换为ADC,DAC和电压
 * 作者   : http://www.keyes-robot.com/ 
*/
#define PIN_ANALOG_IN  34  //薄膜压力传感器的引脚
void setup() {
  Serial.begin(9600);
}

//在loop()中，使用analogRead()函数获取ADC值，
//然后使用map()函数将该值转换为8位精度DAC值。
//输入输出电压按上式计算，
//最后将信息打印出来。
void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);
  int dacVal = map(adcVal, 0, 4095, 0, 255);
  double voltage = adcVal / 4095.0 * 3.3;
  Serial.printf("ADC Val: %d, \t DAC Val: %d, \t Voltage: %.2fV\n", adcVal, dacVal, voltage);
  delay(200);
}