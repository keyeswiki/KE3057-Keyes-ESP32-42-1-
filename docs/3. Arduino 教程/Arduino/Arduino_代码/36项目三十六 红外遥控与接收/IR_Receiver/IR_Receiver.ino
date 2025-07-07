/*  
 * 名称   : IR_Receiver
 * 功能   : 解码红外线遥控器，通过串口打印出来
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <IRremote.hpp>  // 引入 IRremote 库
#define DECODE_NEC  // 只启用 NEC 协议
const int IR_Pin = 4;  //红外接收模块数据引脚为IO4

void setup()
{
  Serial.begin(115200);  // 初始化串口通信
  while (!Serial);  // 等待串口初始化完成
  Serial.println(F("Ready to receive NEC IR signals..."));
  IrReceiver.begin(IR_Pin, ENABLE_LED_FEEDBACK);  // 启动接收，使用引脚 IO4
}

void loop()
{
  if (IrReceiver.decode()) 
  {  // 检测是否接收到红外信号
    if (IrReceiver.decodedIRData.protocol != UNKNOWN) 
    {
      // 打印接收到的按键值，转换为十进制
      long IR_Value = IrReceiver.decodedIRData.command;
      Serial.print("IR Value:");
      Serial.println(IR_Value);  // 以十进制打印按键值
      delay(100);
    }
    IrReceiver.resume();  // 准备接收下一个红外信号
  }
}
