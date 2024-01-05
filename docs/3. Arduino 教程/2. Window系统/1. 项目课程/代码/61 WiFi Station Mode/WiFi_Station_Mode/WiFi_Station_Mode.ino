/*
 * 名称   : WiFi Station Mode
 * 功能   : 使用ESP32连接到路由器
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <WiFi.h> //包含ESP32的WiFi Library头文件

//请输入正确的路由器名称和密码
const char *ssid_Router     = "ChinaNet_2.4G"; //输入路由器名称
const char *password_Router = "ChinaNet@233"; //输入路由器密码

void setup(){
  Serial.begin(115200);
  delay(2000);
  Serial.println("Setup start");
  WiFi.begin(ssid_Router, password_Router);//将ESP32设置为站模式并将其连接到路由器
  Serial.println(String("Connecting to ")+ssid_Router);
//每0.5s检查ESP32与路由器连接是否成功
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected, IP address: ");
  Serial.println(WiFi.localIP());//串口监视器输出分配给ESP32的IP地址
  Serial.println("Setup End");
}
 
void loop() {
}