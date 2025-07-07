/*  
 * 名称   : IR Control LED
 * 功能   : 红外遥控LED开关
 * 作者   : http://www.keyes-robot.com/ 
*/

#include <IRremote.hpp>  // 引入 IRremote 库
#define DECODE_NEC  // 只启用 NEC 协议
const int IR_Pin = 35;  //红外接收模块数据引脚为IO35
int led = 5;//LED连接到GPIO5
boolean flag = true;  //LED标志位

void setup() 
{
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  while (!Serial);  // 等待串口初始化完成
  Serial.println(F("Ready to receive NEC IR signals..."));
  IrReceiver.begin(IR_Pin, ENABLE_LED_FEEDBACK);  // 启动接收，使用引脚 IO35
}

void loop() 
{
  if (IrReceiver.decode()) 
  {  // 检测是否接收到红外信号
    if (IrReceiver.decodedIRData.protocol != UNKNOWN) 
    {
      // 打印接收到的按键值，转换为十进制
      long IR_Value = IrReceiver.decodedIRData.command;
      Serial.print(IR_Value);  // 以十进制打印按键值
      delay(100);
      handleControl(IR_Value);      // 处理来自远程控制的命令
    }
    IrReceiver.resume();  // 准备接收下一个红外信号
  }
}

void handleControl(unsigned long value)
{
  if (value == 64 && flag == true)
  { // 接收数字“OK” 
    analogWrite(led, 255); //打开LED
    delay(10);
    Serial.println("\tled on");
    flag = false;
  } 
  else if (value == 64 && flag == false)
  { // 接收数字“OK”
    analogWrite(led, 0); //关闭LED
    delay(10);
    Serial.println("\tled off"); 
    flag = true;
  }
  else if(value == 22)
  {
    analogWrite(led, 85);
    Serial.println("\tweak light");
    delay(10);
  } 
  else if(value == 25)
  {
    analogWrite(led, 170);
    delay(10);
    Serial.println("\tnormal light");
  } 
  else if(value == 13)
  {
    analogWrite(led, 255);
    delay(10);
    Serial.println("\tstrong light");
  }
}