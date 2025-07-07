/*  
 * 名称   : Encoder
 * 功能   : 旋转编码器模块计数
 * 作者   : http://www.keyes-robot.com/ 
*/

int Encoder_DT  = 27;
int Encoder_CLK  = 14;
int Encoder_Switch = 16;
int Encoder_Count;
 
void setup()
{
  Serial.begin(115200);
  pinMode (Encoder_DT, INPUT);
  pinMode (Encoder_CLK, INPUT);
  pinMode (Encoder_Switch, INPUT);
}
 
 
int lastClk = HIGH;
 
 
void loop() 
{
  int newClk = digitalRead(Encoder_CLK);
  if (newClk != lastClk) 
  {
    // 在CLK引脚上有一个变化
    lastClk = newClk;
    int dtValue = digitalRead(Encoder_DT);
    if (newClk == LOW && dtValue == HIGH) 
    {
      Encoder_Count ++;
      Serial.println(Encoder_Count);
    }
    if (newClk == LOW && dtValue == LOW) 
    {
      Encoder_Count--;
      Serial.println(Encoder_Count);
    }
    delay(100);
  }

  if (digitalRead(Encoder_Switch) == 0)
  {
    delay(5);
    if (digitalRead(Encoder_Switch) == 0) 
    {
      Serial.println("Switch pressed");
      while (digitalRead(Encoder_Switch) == 0);
    }
    delay(100);
  }
}