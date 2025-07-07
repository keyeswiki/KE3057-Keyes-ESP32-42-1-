/*
 * 名称   : Reed Switch
 * 功能   : 读取簧片传感器的值
 * 作者   : http://www.keyes-robot.com/ 
*/
int val = 0;
int reedPin = 5;   //定义连接到干簧管模块的信号引脚为GPIO5

void setup()
{
  Serial.begin(115200);  //波特率设置为115200
  pinMode(reedPin, INPUT);  //设置干簧管模块信号引脚为输入模式
}

void loop() 
{
  val = digitalRead(reedPin);  //读取干簧管模块信号引脚数字电平
  Serial.print(val);  //在串口打印出来
  if (val == 0) 
  {   //附近有一个磁场
    Serial.println("\t A magnetic  field");
  }
  else 
  {   //附近没有磁场
    Serial.println("\t There is no magnetic field");
  }
  delay(100);
}