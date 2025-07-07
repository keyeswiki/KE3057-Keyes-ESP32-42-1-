/*
 * 名称   : Blink
 * 功能   : led 闪烁 1s
 * 作者   : http://www.keyes-robot.com/ 
*/
int ledPin = 5;       //定义LED引脚连接到GPIO5

void setup() 
{
  pinMode(ledPin, OUTPUT);      //设置输出模式
}

void loop() 
{
  digitalWrite(ledPin, HIGH);       //输出高电平，打开led
  delay(1000);//延时 1000 ms
  digitalWrite(ledPin, LOW);        //输出低电平，关闭led
  delay(1000);//延时 1000 ms
}
