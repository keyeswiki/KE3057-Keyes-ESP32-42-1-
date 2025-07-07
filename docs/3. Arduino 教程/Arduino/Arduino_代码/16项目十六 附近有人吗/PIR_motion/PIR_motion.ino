/*
 * 名称   : PIR motion
 * 功能   : 读取人体红外传感器的数值
 * 作者   : http://www.keyes-robot.com/ 
*/
int val = 0;
int pirPin = 5;   //PIR运动传感器的引脚定义为GPIO5

void setup() 
{
  Serial.begin(115200);   
  pinMode(pirPin, INPUT);    //将传感器设置为输入模式
}

void loop() 
{
  val = digitalRead(pirPin);    //读取传感器值
  Serial.print(val);    //打印传感器值
  if (val == 1) 
  {    //附近有人移动，输出高电平
    Serial.println("\t Some body is in this area!");
  }
  else 
  {    //如果附近没有人移动，输出低电平
    Serial.println("\t No one!");
  }
  delay(100);
}