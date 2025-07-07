/*
 * 名称   : Classic Bluetooth
 * 功能   : ESP32通过蓝牙与手机通信，并通过串口打印手机数据
 * 作者   : http://www.keyes-robot.com/ 
*/
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
String buffer;

void setup() 
{
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //蓝牙设备名称
  Serial.println("\nThe device started, now you can pair it with bluetooth!");
}

void loop() 
{
  if (Serial.available()) 
  {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) 
  {
    Serial.write(SerialBT.read());
  }
  delay(20);
}