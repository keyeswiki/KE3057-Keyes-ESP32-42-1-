/*
 * 名称   : Traffic_Light
 * 功能   : 模拟交通灯
 * 作者   : http://www.keyes-robot.com/ 
*/
int redPin = 5;          // 红色LED连接GPIO5
int yellowPin = 13;   // 黄色LED连接到GPIO13
int greenPin = 12;    // 绿色LED连接GPIO12

void setup() 
{
  //LED接口设置为输出模式
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() 
{
  digitalWrite(greenPin, HIGH);   //点亮绿色LED
  delay(5000);   //亮5秒
  digitalWrite(greenPin, LOW);   //关闭绿色LED
  for (int i = 0; i < 3; i++) //循环三次
  {  
    digitalWrite(yellowPin, HIGH);  //点亮黄色LED
    delay(500);  //亮0.5秒
    digitalWrite(yellowPin, LOW);  //熄灭黄色LED
    delay(500);  //灭0.5秒
  }
  digitalWrite(redPin, HIGH);   //点亮红色LED
  delay(5000);  //亮5秒
  digitalWrite(redPin, LOW);   //关闭红色LED
}
