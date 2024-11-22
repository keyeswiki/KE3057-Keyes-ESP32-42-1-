/*  
 * 名称   : Temperature sensor
 * 功能   : 用热敏电阻制作温度计
 * 作者   : http://www.keyes-robot.com/ 
*/
#define PIN_ANALOG_IN   34
void setup() {
  Serial.begin(9600);
}

void loop() {
  int adcValue = analogRead(PIN_ANALOG_IN);    //读ADC引脚
   float Rt=0;      //NTC 热敏电阻
   float R=10000;   //具有固定电阻值的10K电阻
   float T2=273.15+25; //转换成开尔文温度
   float B=3950;    //B值是热敏电阻的一个重要参数
   float K=273.15;  //开氏度 (K°)
   float VR=0;
   VR = (float)(adcValue / 4095.0 * 3.3);  //转换成电压值
   Rt = (3.3 - VR) / VR * 4700;    //计算NTC热敏电阻
   float temp = 1/(1/T2+log(Rt/R)/B)-K+0.5;//计算温度
  Serial.printf("ADC value : %d,\tVoltage : %.2fV, \tTemperature : %.2fC\n", adcValue, VR, temp);
  delay(1000);
}