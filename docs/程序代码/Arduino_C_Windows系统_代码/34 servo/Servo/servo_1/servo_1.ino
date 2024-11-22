/*
 * 名称   : Servo_1
 * 功能   : 舵机旋转角度0 -> 90 -> 180，重复
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <ESP32Servo.h>

Servo myservo;  //创建伺服对象来控制伺服电机

int servoPin = 4;  // 伺服电机引脚

void setup() {
  myservo.setPeriodHertz(50);           //设置伺服电机频率为50Hz
  myservo.attach(servoPin, 500, 2500);  //将servoPin上的值映射到伺服对象上
}

void loop() {
  myservo.write(0); //旋转到0度
  delay(1000); //延迟1s
  myservo.write(90); //旋转到90度
  delay(1000); //延迟1s
  myservo.write(180); //旋转到180度
  delay(1000); //延迟1s
}