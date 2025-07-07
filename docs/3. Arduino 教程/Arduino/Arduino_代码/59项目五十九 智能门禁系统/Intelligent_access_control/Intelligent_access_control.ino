/* 
 * 名称   : Intelligent_access_control
 * 功能   : RFID控制舵机模拟开门
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <Wire.h>
#include "MFRC522_I2C.h"
#include <ESP32Servo.h>  // ESP32专用舵机库

// 硬件配置
#define SERVO_PIN 4     // 舵机信号线接GPIO13
#define I2C_ADDR 0x28    // RFID模块I2C地址
MFRC522 mfrc522(I2C_ADDR);
Servo myServo;           // 创建舵机对象

// 预授权卡UID列表（根据实际卡号修改）
byte authorizedUIDs[][4] = 
{
  {0x02, 0x52, 0x14, 0x53},  // 卡1
  {0x86, 0x5E, 0xE0, 0x6C}   // 卡2
};

void setup() 
{
  Serial.begin(115200);
  
  // 初始化舵机
  myServo.attach(SERVO_PIN);
  myServo.write(0);      // 上电归零

  // 初始化RFID
  Wire.begin();
  mfrc522.PCD_Init();
  if (!checkRFIDConnection()) 
  {
    Serial.println("RFID initialization failed!");
    while(1); // 停止执行
  }
  Serial.println("Waiting for authorized card...");
}

void loop() 
{
  // 检测RFID卡
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) 
  {
    // 验证UID
    if (checkAuthorization()) 
    {
      Serial.println("Access Granted!");
      activateServo();
    } 
    else 
    {
      Serial.println("Access Denied - Unauthorized card");
    }
    mfrc522.PICC_HaltA(); // 停止读卡
  }
  delay(100);
}

// 舵机控制函数
void activateServo() 
{
  myServo.write(180);    // 转到180度
  Serial.println("Open the door!");
  delay(2000);           // 保持2秒
  myServo.write(0);      // 返回0度
  Serial.println("Close the door!");
}

// 验证卡权限
bool checkAuthorization() 
{
  Serial.print("Scanned UID:");
  // 打印当前卡片UID
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();
  
  // 检查是否在授权列表中
  for (int i = 0; i < sizeof(authorizedUIDs)/4; i++) 
  {
    if (memcmp(mfrc522.uid.uidByte, authorizedUIDs[i], 4) == 0) 
    {
      return true;
    }
  }
  return false;
}

// 检查RFID连接
bool checkRFIDConnection() 
{
  byte v = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
  if (v == 0x00 || v == 0xFF) 
  {
    Serial.println("RFID module not found!");
    return false;
  }
  Serial.print("RFID Firmware Version: 0x");
  Serial.println(v, HEX);
  return true;
}