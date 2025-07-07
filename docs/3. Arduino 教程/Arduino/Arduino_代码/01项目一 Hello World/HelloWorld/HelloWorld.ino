/*
 * 名称   : Hello World
 * 功能   : 输入字母R，串口显示“Hello World”。
 * 作者   : http://www.keyes-robot.com/ 
*/
char val;     // 定义变量val 

void setup()
{
  Serial.begin(115200);     // 设置波特率为115200
}

void loop()
{
  if (Serial.available() > 0) 
  {
    val=Serial.read();     // 读取赋值给"val"的值
    if(val=='R')     // 检查输入的字母“R”
    {  // if so,    
     Serial.println("Hello World!");      //显示“Hello World !”
    }
  }
}