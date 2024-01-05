/*  
 * 名称   : smart window
 * 功能   : 水滴传感器控制舵机转动
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <ESP32Servo.h> //导入舵机库文件
int adcVal = 0;         //保存液滴传感器输出的ADC值的变量
int servoPin = 4;       // 定义伺服引脚
Servo myservo;          //定义舵机类的实例

#define PIN_ADC    34   //水滴传感器的引脚

void setup(){
  Serial.begin(9600);
  pinMode(PIN_ADC, INPUT);
  myservo.setPeriodHertz(50);           //标准50赫兹伺服
  myservo.attach(servoPin, 500, 2500);  // 将servoPin上的伺服附加到伺服对象上
}

void loop(){
  adcVal = analogRead(PIN_ADC); //液滴传感器连接到模拟端口GP34
  Serial.println(adcVal);
  if (adcVal > 2000) { //模拟值大于2000
    myservo.write(0);  //关上窗户
    delay(500); //给舵机转向的时间
  } else { // 没有下雨
    myservo.write(180); //打开窗户
    delay(500); //延迟500毫秒
  }
}