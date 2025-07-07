/*  
 * 名称   : PIR alarm
 * 功能   : PIR控制蜂鸣器
 * 作者   : http://www.keyes-robot.com/ 
*/
int item = 0;

void setup() 
{
  pinMode(12, INPUT);  //PIR运动传感器连接GPIO12，设置为输入模式
  pinMode(13, OUTPUT); //将主用蜂鸣器连接到GPIO13上，并设置为输出模式
  pinMode(5, OUTPUT);  //将LED连接到GPIO5上，并设置为输出模式
}

void loop() 
{
  item = digitalRead(12);//读取红外热释传感器输出的数字液位信号
  if (item == 1) 
  {  //运动检测
    digitalWrite(13, HIGH); //打开蜂鸣器
    digitalWrite(5, HIGH);  //打开LED
    delay(200);//延迟 200ms
    digitalWrite(13, LOW); //关掉蜂鸣器
    digitalWrite(5, LOW);  //关闭LED
    delay(200);//延迟 200ms
  } 
  else 
  {  //没有检测到任何信号或数据
    digitalWrite(13, LOW); //关掉蜂鸣器
    digitalWrite(5, LOW);  //关闭LED
  }
}