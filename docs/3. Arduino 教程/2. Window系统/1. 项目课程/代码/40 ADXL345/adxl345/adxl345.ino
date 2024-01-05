/*  
 * 名称   : ADXL345
 * 功能   : 读取ADXL345的X/Y/Z值
 * 作者   : http://www.keyes-robot.com/ 
*/
#include "adxl345_io.h"
adxl345 adxl345(21, 22);

float out_X, out_Y, out_Z;

void setup() {
  Serial.begin(57600);//启动串口监视器，波特率设置为57600
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