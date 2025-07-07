/*
 * 名称   : line tracking
 * 功能   : 读取循迹传感器值
 * 作者   : http://www.keyes-robot.com/ 
*/
int val = 0;

void setup() 
{
  Serial.begin(115200); //设置波特率为115200
  pinMode(5, INPUT);  //将传感器引脚设置为输入模式
}

void loop() 
{
  val = digitalRead(5);   //读取循迹传感器的数字电平输出
  Serial.print(val);      //打印循迹传感器的读取到的数字电平的值
  if (val == 0) 
  {  //检测到白色值为0
    Serial.println("\t White");
    delay(100);
  }
  else 
  {  //检测到黑色值为1
    Serial.println("\t Black");
    delay(100);
  }
}