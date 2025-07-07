/*
 * 名称   : collision sensor
 * 功能   : 读取碰撞传感器的值
 * 作者   : http://www.keyes-robot.com/ 
*/
int val = 0;

void setup() 
{
  Serial.begin(115200);  //波特率设置为115200
  pinMode(5, INPUT);   //设置碰撞传感器的引脚GPIO5为输入模式
}

void loop() 
{
  val = digitalRead(5);  //读取碰撞传感器的值
  Serial.print(val);      //打印碰撞传感器的值
  if (val == 0) 
  {   //碰撞
    Serial.println("\t The end of this!");
    delay(100);
  }
  else 
  {    //无碰撞
    Serial.println("\t All going well");
    delay(100);
  }
}