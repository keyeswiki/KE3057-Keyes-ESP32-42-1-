/*  
 * 名称   : heat abstractor
 * 功能   : DS18B20控制一个四位数管和一个电机模拟散热装置
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <DS18B20.h>
#include "TM1650.h" //导入TM1650库文件
//两个端口分别为GP21和GP22
#define DIO 21
#define CLK 22
TM1650 DigitalTube(CLK,DIO);

//DS18B20引脚为12
DS18B20 ds18b20(12);
void setup() 
{
  Serial.begin(115200);
  DigitalTube.setBrightness();  //设置亮度，0- 7，默认值:2
  DigitalTube.displayOnOFF();   //显示打开或关闭，0=显示关闭，1=显示打开，默认值:1
  for(char b=1;b<5;b++)
  {
    DigitalTube.clearBit(b);    //DigitalTube.clearBit(0~3);清晰位显示
  }
  // DigitalTube.displayDot(1,true);//Bit0显示点。在displayBit()之前使用。
  DigitalTube.displayBit(1,0);  //DigitalTube.Display(bit,number); bit=0---3  number=0---9
  //电机连接到5 13
  pinMode(5, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() 
{
  double temp = ds18b20.GetTemp();//读取温度
  temp *= 0.0625;//转换精度为0.0625/LSB
  Serial.println(temp);
  displayFloatNum(temp);//4位数码管显示温度值
  if (temp > 30) 
  {//当温度超过30℃时，打开风扇
    digitalWrite(5, LOW);
    digitalWrite(13, HIGH);
  } else 
  {//否则，请关闭风扇
    digitalWrite(5, LOW);
    digitalWrite(13, LOW);
  }
  delay(100);
}

void displayFloatNum(float temp)
{
  if(temp > 9999)
    return;
  int dat = temp*10;
   //DigitalTube.displayDot(2,true); //Bit0显示点  在displayBit()之前使用。
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