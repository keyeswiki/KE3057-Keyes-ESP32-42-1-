/*  
 * 名称   : Ultrasonic radar
 * 功能   : 超声波控制四位数管，蜂鸣器和RGB灯模拟超声波雷达
 * 作者   : http://www.keyes-robot.com/ 
*/
#include "TM1650.h" //导入TM1650库文件
//接口为GPIO21和GPIO22
#define DIO 21
#define CLK 22
TM1650 DigitalTube(CLK,DIO);

#define AUDIO_PIN   2    //定义喇叭引脚为GPIO2

int TrigPin = 13; //设置Trig引脚为GPIO13
int EchoPin = 12; //设置Echo引脚为GPIO12
int distance;     //超声波测量距离

// RGB引脚定义
#define RED_PIN   4
#define GREEN_PIN 32
#define BLUE_PIN  33

float checkdistance() 
{ //得到的距离
  // 事先给一个短的低电平，以确保一个干净的高脉冲;
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  // 传感器由10微秒或更长时间的高脉冲触发
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  // 从传感器读取信号:一个高电平脉冲
  // 它的持续时间是从发送ping命令到从对象接收回显的时间(以微秒为单位)
  float distance = pulseIn(EchoPin, HIGH) / 58.00;  //转换成距离
  delay(300);
  return distance;
}

void setup() 
{
  pinMode(AUDIO_PIN, OUTPUT);  // 设置喇叭为输出模式
  DigitalTube.setBrightness();  //设置亮度，0- 7，默认值:2
  DigitalTube.displayOnOFF();   //显示打开或关闭，0=显示关闭，1=显示打开，默认值:1
  for(char b=1;b<5;b++)
  {
    DigitalTube.clearBit(b);    //DigitalTube.clearBit(0 to 3); 清空位显示
  }
  
  DigitalTube.displayBit(1,0);  //DigitalTube.Display(bit,number); bit= 0 - 3，number= 0 - 9
  pinMode(TrigPin, OUTPUT);     //设置Trig引脚作为输出
  pinMode(EchoPin, INPUT);      //设置Echo引脚作为输入
}

void loop() 
{
  distance = checkdistance();//超声波测距
  displayFloatNum(distance); //数码管显示距离
  if (distance <= 10) 
  {  
    setColor(255, 0, 0); //红色 
    playTone(1000, 1000);  // 频率1kHz，持续1秒
  } 
  else if (distance > 10 && distance <= 20) 
  {
    setColor(0, 255, 0); //绿色
  } 
  else 
  {
    setColor(0, 0, 255); //蓝色
  }
}

void displayFloatNum(float distance)
{
  if(distance > 9999)
    return;
  int dat = distance*10;
  if(dat/10000 != 0)
  {
    DigitalTube.displayBit(0, dat%100000/10000);  
    DigitalTube.displayBit(1, dat%10000/1000);
    DigitalTube.displayBit(2, dat%1000/100);
    DigitalTube.displayBit(3, dat%100/10);
    return;
  }
  if(dat%10000/1000 != 0)
  {
    DigitalTube.clearBit(0); 
    DigitalTube.displayBit(1, dat%10000/1000); 
    DigitalTube.displayBit(2, dat%1000/100);
    DigitalTube.displayBit(3, dat%100/10);
    return;
  }
  if(dat%1000/100 != 0)
  {
    DigitalTube.clearBit(0); 
    DigitalTube.clearBit(1);
    DigitalTube.displayBit(2, dat%1000/100);
    DigitalTube.displayBit(3, dat%100/10);  
    return;
  }
  DigitalTube.clearBit(0); 
  DigitalTube.clearBit(1);
  DigitalTube.clearBit(2);
  DigitalTube.displayBit(3, dat%100/10);
}

void setColor(int red, int green, int blue) 
{
  analogWrite(RED_PIN,red);
  analogWrite(GREEN_PIN,green);
  analogWrite(BLUE_PIN,blue);
}

void playTone(int freq, int durationMs) 
{
  long periodUs = 1000000 / freq;      // 计算周期（微秒）
  long halfPeriod = periodUs / 2;      // 半周期时间
  long startTime = millis();

  while (millis() - startTime < durationMs) 
  {
    digitalWrite(AUDIO_PIN, HIGH);
    delayMicroseconds(halfPeriod);     // 高电平半周期
    digitalWrite(AUDIO_PIN, LOW);
    delayMicroseconds(halfPeriod);     // 低电平半周期
  }
}