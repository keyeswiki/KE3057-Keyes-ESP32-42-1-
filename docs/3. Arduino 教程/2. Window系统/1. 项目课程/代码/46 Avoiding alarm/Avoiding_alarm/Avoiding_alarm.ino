/*  
 * 名称   : Avoiding alarm
 * 功能   : 避障传感器控制蜂鸣器
 * 作者   : http://www.keyes-robot.com/ 
*/
int item = 0;
void setup() {
  pinMode(12, INPUT);  //避障传感器连接GPIO12，设置为输入模式
  pinMode(13, OUTPUT); //将蜂鸣器连接到GPIO13上并设置为输出模式
}

void loop() {
  item = digitalRead(12);//读取避障传感器输出的电平值
  if (item == 0) {//障碍物检测
    digitalWrite(13, HIGH);//蜂鸣器响起
  } else { //未检测到障碍物
    digitalWrite(13, LOW); //蜂鸣器关闭
  }
  delay(100);//延迟100ms
}