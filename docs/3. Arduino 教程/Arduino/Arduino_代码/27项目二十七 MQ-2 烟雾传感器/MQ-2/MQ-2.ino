/*  
 * 名称   : MQ2
 * 功能   : MQ-2模拟气体传感器检测到的气体转化为ADC,DAC和电压值
 * 作者   : http://www.keyes-robot.com/ 
*/
//MQ_2两个引脚分别为13、34
#define PIN_ANALOG_IN  34 
int digitalPin =  13;

//以下两个变量分别保存数字信号和adc值
int analogVal = 0;
int adcVal = 0;

void setup() 
{
  Serial.begin(115200);
  pinMode(digitalPin, INPUT); //数字引脚13设置为输入模式
}

//在loop()中，digitalRead()函数用于获取数字值，
//analogRead()函数用于获取ADC值。
//然后使用map()函数将该值转换为8位精度DAC值。
//输入输出电压按下面公式计算，
//最后将信息打印出来。
void loop() 
{
  int digitalVal = digitalRead(digitalPin);  //读取数字信号;
  int adcVal = analogRead(PIN_ANALOG_IN);
  int dacVal = map(adcVal, 0, 4095, 0, 255);
  double voltage = adcVal / 4095.0 * 5;
  Serial.printf("digitalVal: %d, \t ADC Val: %d, \t DAC Val: %d, \t Voltage: %.2fV",digitalVal, adcVal, dacVal, voltage);
  if (digitalVal == 1) 
  {
    Serial.println("\t Normal");
  }
  else 
  {
    Serial.println("\t Exceeding");
  }
  delay(200); //延迟时间200ms
}