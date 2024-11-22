/*  
 * 名称   : Flame Alarm
 * 功能   : 通过火焰传感器控制蜂鸣器
 * 作者   : http://www.keyes-robot.com/ 
*/
int item = 0;
void setup() {
  Serial.begin(9600);
  pinMode(13, INPUT);  //火焰传感器数字引脚连接到GPIO13
  pinMode(5, OUTPUT);  //蜂鸣器引脚连接GPIO5
}

void loop() {
  item = digitalRead(13); //读取火焰传感器的数字电平输出
  Serial.println(item);   //换行打印电平信号
  if (item == 0) { //火焰探测
    digitalWrite(5, HIGH); //打开蜂鸣器
  } else { //否则，请关闭蜂鸣器
    digitalWrite(5, LOW);
  }
  delay(100); //延迟100毫秒
}