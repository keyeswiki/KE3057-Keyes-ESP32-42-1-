/*
 * 名称   : RGB
 * 功能   : 使用RGBLED显示随机颜色
 * 作者   : http://www.keyes-robot.com/ 
*/
// RGB引脚定义
#define RED_PIN   32
#define GREEN_PIN 4
#define BLUE_PIN  2

void setup() 
{
  //将控制引脚设置为输出模式
  pinMode(RED_PIN,OUTPUT);
  pinMode(GREEN_PIN,OUTPUT);
  pinMode(BLUE_PIN,OUTPUT);
}

void loop() 
{
  // 生成随机颜色值 (0~256)
  int r = random(256);
  int g = random(256);
  int b = random(256);

  analogWrite(RED_PIN,r);
  analogWrite(GREEN_PIN,g);
  analogWrite(BLUE_PIN,b);
  delay(1000);
}