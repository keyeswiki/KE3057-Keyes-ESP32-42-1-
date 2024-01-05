/*  
 * 名称   : IR Control LED
 * 功能   : 红外遥控LED开关
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t recvPin = 35;  // 红外接收GPIO35
IRrecv irrecv(recvPin);       // 创建一个用于接收类的类对象
decode_results results;       // 创建一个解码结果类对象
int led = 5;//LED连接到GPIO5
boolean flag = true;  //LED标志钻头

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();                  //启动接收器
  pinMode(led, OUTPUT);
  ledcSetup(0, 1000, 8);//设置PWM通道
  ledcAttachPin(5, 0);  //将led引脚连接到PWM通道
}

void loop() {
  if(irrecv.decode(&results)) {        // 等待解码
    serialPrintUint64(results.value, HEX);// 输出解码结果
    Serial.print("");
    handleControl(results.value);      // 处理来自远程控制的命令
    irrecv.resume();                   // 接收下一个值
  }
}

void handleControl(unsigned long value){
  if (value == 0xFF02FD && flag == true){ // 接收数字“OK” 
    ledcWrite(0, 170); //打开LED
    delay(10);
    Serial.println("  led on");
    flag = false;
  } 
  else if (value == 0xFF02FD && flag == false){ // 接收数字“OK”
    ledcWrite(0, 0); //打开LED
    delay(10);
    Serial.println("  led off"); 
    flag = true;
  }
  else if(value == 0xFF6897){
    ledcWrite(0, 85);
    Serial.println("  weak light");
    delay(10);
  } 
  else if(value == 0xFF9867){
    ledcWrite(0, 170);
    delay(10);
    Serial.println("  normal light");
  } 
  else if(value == 0xFFB04F){
    ledcWrite(0, 255);
    delay(10);
    Serial.println("  strong light");
  }
}