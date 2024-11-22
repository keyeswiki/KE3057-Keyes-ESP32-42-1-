/*
   adxl345软件IIC子程序,适用于arduino, esp32, raspberry pi pico
   2022/2/25
   Dengfei
   示例代码只读取温湿度整数部分 
*/
#include "adxl345_io.h"
//
adxl345 adxl345(9, 10);

float out_X, out_Y, out_Z;

void setup() {
  Serial.begin(57600);//启动串口监视器,并设置波特率为57600
  adxl345.Init();
}

void loop() {
  adxl345.readXYZ(&out_X, &out_Y, &out_Z);
  Serial.print(out_X);
  Serial.print("g   ");
  Serial.print(out_Y);
  Serial.print("g   ");
  Serial.print(out_Z);
  Serial.println("g");
  delay(100);

}
