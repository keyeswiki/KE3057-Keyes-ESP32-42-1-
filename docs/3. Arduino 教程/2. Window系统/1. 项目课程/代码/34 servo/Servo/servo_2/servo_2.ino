/*
 * 名称   : Servo_2
 * 功能   : 控制伺服电机进行扫动
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <ESP32Servo.h>

Servo myservo;  //创建伺服对象来控制伺服电机

int posVal = 0;    // 定义一个变量，存储伺服电机位置
int servoPin = 4;  // 伺服电机引脚

void setup() {
  myservo.setPeriodHertz(50);           //设置伺服电机频率为50Hz
  myservo.attach(servoPin, 500, 2500);  //将servoPin上的值映射到伺服对象上
}
void loop() {

  for (posVal = 0; posVal <= 180; posVal += 1) { // 将servoPin上的伺服附加到伺服对象上
    // 以1度为步
    myservo.write(posVal);       // 告诉伺服电机到变量“pos”的位置
    delay(15);                   // 等待15ms让伺服电机到达位置
  }
  for (posVal = 180; posVal >= 0; posVal -= 1) { // 从180°到0°
    myservo.write(posVal);       // 告诉伺服电机到变量“pos”的位置
    delay(15);                   // 等待15ms让伺服电机到达位置
  }
}