/*
 * 名称   : Bluetooth Control LED
 * 功能   : 手机通过蓝牙控制esp32的led
            当手机发送“LED_on”时，ESP32的LED灯就会打开。
            当手机发送“LED_off”时，ESP32的LED灯就会关闭。
 * 作者   : http://www.keyes-robot.com/ 
*/
#include "BluetoothSerial.h"
#include "string.h"
#define LED 5
BluetoothSerial SerialBT;
char buffer[20];
static int count = 0;
void setup() {
  pinMode(LED, OUTPUT);
  SerialBT.begin("ESP32test"); //蓝牙设备名称

  Serial.begin(115200);
  Serial.println("\nThe device started, now you can pair it with bluetooth!");
}

void loop() {
  while(SerialBT.available())
  {
    buffer[count] = SerialBT.read();
    count++;
  }
  if(count>0){
    Serial.print(buffer);
    if(strncmp(buffer,"led_on",6)==0){
      digitalWrite(LED,HIGH);
    }
    if(strncmp(buffer,"led_off",7)==0){
      digitalWrite(LED,LOW);
    }
    count=0;
    memset(buffer,0,20);
  }
}