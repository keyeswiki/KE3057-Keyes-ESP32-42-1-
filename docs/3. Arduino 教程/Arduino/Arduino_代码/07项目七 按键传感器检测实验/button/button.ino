/*
 * 名称   : button
 * 功能   : 读键值
 * 作者   : http://www.keyes-robot.com/ 
*/
int val = 0;            //用于存储键值
int button = 5;         //将按钮的引脚连接到GPIO5

void setup() 
{
  Serial.begin(115200);      //启动串口监视器，设置波特率为115200
  pinMode(button, INPUT);  //设置按钮引脚为输入模式
}

void loop() 
{
  val = digitalRead(button);  // 读取按钮状态（0或1）
  Serial.print(val);          // 打印原始电平值
  if (val == 0) 
  {             // 按钮按下（低电平）
    Serial.println("\t Press the botton");
    delay(100);               // 防抖延迟
  }
  else 
  {                      // 按钮松开（高电平）
    Serial.println("\t Loosen the botton");
    delay(100);               // 防抖延迟
  }
}