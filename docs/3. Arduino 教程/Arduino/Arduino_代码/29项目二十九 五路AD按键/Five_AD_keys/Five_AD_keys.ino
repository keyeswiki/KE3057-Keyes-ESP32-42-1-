/*  
 * 名称   : Five AD Keys
 * 功能   : 读取五路AD按键的值
 * 作者   : http://www.keyes-robot.com/ 
*/
int val = 0;
int ADkey = 34; //定义五路AD按键连接到GPIO34

void setup() 
{
  Serial.begin(115200); 
}

void loop() 
{
  val = analogRead(ADkey);  //读取五路AD引脚的模拟值，并将其赋给变量val
  Serial.print(val);  //换行符输出变量val
  if (val <= 500) 
  { //没有按下按钮时，Val小于或等于500
    Serial.println("   no key  is pressed");
  } 
  else if (val <= 1000) 
  { //当按下5键时，val在500到1000之间
    Serial.println("   SW5 is pressed");
  } 
  else if (val <= 2000) 
  { //当按下4键时，val在1000到2000之间
    Serial.println("   SW4 is pressed");
  } 
  else if (val <= 3000) 
  { //当按下3键时，val在2000到3000之间
    Serial.println("   SW3 is pressed");
  } 
  else if (val <= 4000) 
  { //当按下2键时，val在3000 ~ 4000之间
    Serial.println("   SW2 is pressed");
  } 
  else 
  {  //当按下1键时，val大于4000
    Serial.println("   SW1 is pressed");
  }
  delay(100);
}