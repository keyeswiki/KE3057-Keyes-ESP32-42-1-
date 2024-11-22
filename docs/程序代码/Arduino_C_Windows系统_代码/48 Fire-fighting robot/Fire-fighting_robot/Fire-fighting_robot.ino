/*  
 * 名称   : Fire-fighting robot
 * 功能   : 火焰传感器控制130风扇模块
 * 作者   : http://www.keyes-robot.com/ 
*/
int item = 0;
void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT); //INA对应IN+，将GPIO5设置为输出模式
  pinMode(13, OUTPUT);//INB对应IN-，将GPIO13置为输出模式
}

void loop() {
  item = analogRead(34);//将火焰传感器连接到GPIO34上，将模拟值读取到Item
  Serial.print(item); //串口显示模拟值
  if (item < 3000) {//3000以下  
    Serial.print("   "); 
    Serial.println("Put out a fire");
    delay(100);
    digitalWrite(5, LOW);//打开电风扇
    digitalWrite(13, HIGH);
    
  } else {//否则，关闭风扇
    Serial.print("   "); 
    Serial.println("No flame detected");
    delay(100);
    digitalWrite(5, LOW);
    digitalWrite(13, LOW);
    
  } 
}
