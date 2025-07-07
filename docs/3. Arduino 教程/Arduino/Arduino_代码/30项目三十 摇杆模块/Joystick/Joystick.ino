/*  
 * 名称   : Joystick
 * 功能   : 从摇杆读取数据
 * 作者   : http://www.keyes-robot.com/ 
*/
int xyzPins[] = {34, 35, 13};   //x,y,z 引脚

void setup() 
{
  Serial.begin(115200);
  pinMode(xyzPins[0], INPUT); //x轴
  pinMode(xyzPins[1], INPUT); //y轴 
  pinMode(xyzPins[2], INPUT_PULLUP);   //z轴是一个按钮
}

// 在loop()中，使用analogRead()读取x轴和y轴的值
//并使用digitalRead()读取z轴的值，然后显示它们。
void loop() 
{
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);
  Serial.println("X,Y,Z: " + String(xVal) + ", " +  String(yVal) + ", " + String(zVal));
  delay(500);
}