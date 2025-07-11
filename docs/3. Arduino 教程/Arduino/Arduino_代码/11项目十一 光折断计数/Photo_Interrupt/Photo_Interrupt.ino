/*
 * 名称   : Photo_Interrupt
 * 功能   : 光传感器计数
 * 作者   : http://www.keyes-robot.com/ 
*/
int PushCounter = 0;  //count变量的初始值为0
int State = 0;        //存储传感器当前的输出状态
int lastState = 0;    //存储传感器最后的输出状态

void setup() 
{
  Serial.begin(115200); //设置波特率为115200
  pinMode(5, INPUT);  //将光捕捉传感器引脚设置为输入模式
}

void loop() 
{
  State = digitalRead(5);   //读取当前状态
  delay(20);                //消抖，防止因信号抖动导致的误判，从而提高准确性
  if (State != lastState) 
  { //如果状态与上次读取的不同
    if (State == 1) 
    {       //遮挡光线时
      PushCounter = PushCounter + 1; //计数 + 1
      Serial.println(PushCounter);   //打印计数 
    }
  }
  lastState = State;  //更新状态
}