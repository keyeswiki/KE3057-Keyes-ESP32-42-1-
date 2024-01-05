/*
 * 名称   : obstacle avoidance sensor
 * 功能   : 读取避障值
 * 作者   : http://www.keyes-robot.com/ 
*/
int val = 0;
void setup() {
  Serial.begin(9600);   //设置波特率为9600
  pinMode(5, INPUT);    //设置引脚GPIO5为输入模式
}

void loop() {
  val = digitalRead(5);  //读取数字电平
  Serial.print(val);     //打印读取的电平信号
  if (val == 0) {  //障碍物检测
    Serial.print("        ");
    Serial.println("There are obstacles");
    delay(100);
  }
  else {  //未发现障碍物
    Serial.print("        ");
    Serial.println("All going well");
    delay(100);
  }
}