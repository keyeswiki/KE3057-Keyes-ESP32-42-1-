/*
 * 名称   : Hall magnetic
 * 功能   : 读取霍尔磁传感器的值
 * 作者   : http://www.keyes-robot.com/ 
*/
int val = 0;
int hallPin = 5;  //霍尔传感器引脚连接GPIO5

void setup() 
{
  Serial.begin(115200);  //波特率设置为115200
  pinMode(hallPin, INPUT);  //设置引脚为输入模式
}

void loop() 
{
  val = digitalRead(hallPin);  //读取霍尔传感器的值
  Serial.print(val);  //打印值
  if (val == 0) 
  {  //感应到南极磁场
    Serial.println("\t The magnetic field at the South Pole!");
  }
  else 
  {  //没有感应到南极磁场
    Serial.println("\t Just be all normal!");
  }
  delay(100);
}