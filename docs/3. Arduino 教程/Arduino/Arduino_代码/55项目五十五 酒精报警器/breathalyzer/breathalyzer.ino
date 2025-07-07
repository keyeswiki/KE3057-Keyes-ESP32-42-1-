/*  
 * 名称   : breathalyzer
 * 功能   : MQ3控制一个蜂鸣器和一个四位数码管来模拟酒精检测仪
 * 作者   : http://www.keyes-robot.com/ 
*/
#include "TM1650.h" //导入TM1650库文件
int adcVal = 0; 
//接口为GPIO21和GPIO22
#define DIO 21
#define CLK 22
TM1650 DigitalTube(CLK,DIO);

void setup() 
{
  Serial.begin(115200);
  DigitalTube.setBrightness();  //设置亮度，0- 7，默认值:2
  DigitalTube.displayOnOFF();   //显示打开或关闭; 0=关闭, 1=打开, default : 1
  for(char b=1;b<5;b++)
  {
    DigitalTube.clearBit(b);    //DigitalTube.clearBit(0 to 3); 清空位显示
  }
  // DigitalTube.displayDot(1,true); //Bit0显示点。在displayBit()之前使用。
  DigitalTube.displayBit(1,0);  //DigitalTube.Display(bit,number); 位= 0 - 3,号= 0 - 9
  pinMode(5, OUTPUT);//蜂鸣器连接GPIO5
}

void loop() 
{
  adcVal = analogRead(34);//读取MQ3的ADC值
  displayFloatNum(adcVal);//四位数管显示adcVal值
  if (adcVal > 3000) 
  {//ADC值大于740
    digitalWrite(5, HIGH);// 蜂鸣报警器
  } 
  else 
  {//否则
    digitalWrite(5, LOW); //关掉蜂鸣器
  }
  delay(100);//延迟100毫秒
}

void displayFloatNum(float adcVal)
{
  if(adcVal > 9999)
    return;
  int dat = adcVal*10;
   //DigitalTube.displayDot(2,true); //Bit0 display dot. Use before displayBit().
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