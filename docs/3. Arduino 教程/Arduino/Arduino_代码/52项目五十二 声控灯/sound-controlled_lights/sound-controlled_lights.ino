/*  
 * 名称   : sound-controlled lights
 * 功能   : 声音传感器控制LED开关
 * 作者   : http://www.keyes-robot.com/ 
*/
int ledPin = 5;    //LED连接到GPIO5
int microPin = 34; //声音传感器连接到GPIO34

void setup() 
{
  Serial.begin(115200); 
  pinMode(ledPin, OUTPUT); //LED为输出模式
}

void loop() 
{
  int val = analogRead(microPin); //读取模拟值
  Serial.print(val); // 串口打印
  if(val > 400)
  { //超过阈值
    digitalWrite(ledPin, HIGH); //LED亮3s，并打印相应信息
    Serial.println("  led on");
    delay(3000);
  }
  else
  { //否则
    digitalWrite(ledPin, LOW); //关闭LED并打印相应信息
    Serial.println("  led off");
  }
  delay(100);
}