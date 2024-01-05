/*  
 * 名称   : IR Receiver
 * 功能   : 解码红外线遥控器，通过串口打印出来
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t recvPin = 4; // 红外接收引脚
IRrecv irrecv(recvPin);     // 创建一个用于接收类的类对象
decode_results results;     // 创建一个解码结果类对象

void setup() {
  Serial.begin(9600);       // 初始化串口，波特率设置为9600
  irrecv.enableIRIn();      // 启动接收器
  Serial.print("IRrecvDemo is now running and waiting for IR message on Pin ");
  Serial.println(recvPin);  // 打印红外线接收针
}

void loop() {
  if (irrecv.decode(&results)) { // 等待解码
    serialPrintUint64(results.value, HEX);// 输出解码结果
    Serial.println("");
    irrecv.resume();             // 释放IRremote，接收下一个值
  }
  delay(1000);
}