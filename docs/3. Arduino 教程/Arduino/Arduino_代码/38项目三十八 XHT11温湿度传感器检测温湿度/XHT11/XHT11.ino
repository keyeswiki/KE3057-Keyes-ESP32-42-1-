/*  
 * 名称   : xht11
 * 功能   : 读取XHT11的温度和湿度值
 * 作者   : http://www.keyes-robot.com/ 
*/
#include "xht11.h"
xht11 xht(13);
unsigned char dht[4] = {0, 0, 0, 0};// 只接收数据的前32位，不接收奇偶校验位

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  if (xht.receive(dht)) 
  { //正确检查时返回true
    Serial.print("RH:");
    Serial.print(dht[0]); //湿度的积分部分DHT[1]为小数部分系列。打印(“%”);
    Serial.print("  Temp:");
    Serial.print(dht[2]); //温度的积分部分DHT[3]为小数部分
    Serial.println("°C");
  } 
  else 
  {    //Read error
    Serial.println("sensor error");
  }
  delay(1000);  //等待设备读取需要1000ms
}