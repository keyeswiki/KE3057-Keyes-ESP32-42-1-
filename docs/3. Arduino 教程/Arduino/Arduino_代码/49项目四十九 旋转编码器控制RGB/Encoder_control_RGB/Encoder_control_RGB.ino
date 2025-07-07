/*  
 * 名称   : Encoder control RGB
 * 功能   : 旋转编码器控制RGB来呈现不同的效果
 * 作者   : http://www.keyes-robot.com/ 
*/
//旋转编码器接口
int Encoder_DT  = 27;
int Encoder_CLK  = 14;
int Encoder_Switch = 16;

int Previous_Output;
int Encoder_Count;

// RGB引脚定义
#define RED_PIN   32
#define GREEN_PIN 4
#define BLUE_PIN  2
int red, green, blue;

int val;
void setup()
{
  Serial.begin(115200);
  //引脚模式声明
  pinMode (Encoder_DT, INPUT);
  pinMode (Encoder_CLK, INPUT);
  pinMode (Encoder_Switch, INPUT);
  pinMode (RED_PIN, OUTPUT);
  pinMode (GREEN_PIN, OUTPUT);
  pinMode (BLUE_PIN, OUTPUT);
  Previous_Output = digitalRead(Encoder_DT); //读取输出DT的初始值
}

void loop() 
{
  if (digitalRead(Encoder_DT) != Previous_Output)
  {
    if (digitalRead(Encoder_CLK) != Previous_Output)
    {
      Encoder_Count ++;
      val = Encoder_Count % 3;
      Serial.printf("%d\t%d\n",Encoder_Count,val);
    }
    else
    {
      Encoder_Count--;
      val = Encoder_Count % 3;
      Serial.printf("%d\t%d\n",Encoder_Count,val);
    }
    delay(100);
  }
  Previous_Output = digitalRead(Encoder_DT);
  if (digitalRead(Encoder_Switch) == 0)
  {
    delay(5);
    if (digitalRead(Encoder_Switch) == 0)
    {
      Serial.println("Switch pressed");
      while (digitalRead(Encoder_Switch) == 0);
    }
  }
  if (val == 0) 
  {
    setColor(255, 0, 0); //红色
  } 
  else if (val == 1) 
  {
    setColor(0, 255, 0); //绿色
  } else 
  {
    setColor(0, 0, 255); //蓝色
  }
}

void setColor(int red, int green, int blue) 
{
  analogWrite(RED_PIN,red);
  analogWrite(GREEN_PIN,green);
  analogWrite(BLUE_PIN,blue);
}