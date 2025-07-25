/*
 * 名称   : WiFi AP
 * 功能   : 设置ESP32开启接入点
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <WiFi.h> //包括ESP32的WiFi Library头文件。

const char *ssid_AP     = "ESP32_WiFi"; //输入路由器名称
const char *password_AP = "12345678"; //输入路由器密码
IPAddress local_IP(192,168,1,108);//配置ESP32自身的IP地址
IPAddress gateway(192,168,1,1);   //设置ESP32本身的网关
IPAddress subnet(255,255,255,0);  //设置ESP32自身的子网掩码

void setup()
{
  Serial.begin(115200);
  delay(2000);
  Serial.println("Setting soft-AP configuration ... ");
  WiFi.disconnect();
  WiFi.mode(WIFI_AP);
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");
  Serial.println("Setting soft-AP ... ");
  boolean result = WiFi.softAP(ssid_AP, password_AP);
  if(result)
  {
    Serial.println("Ready");
    Serial.println(String("Soft-AP IP address = ") + WiFi.softAPIP().toString());
    Serial.println(String("MAC address = ") + WiFi.softAPmacAddress().c_str());
  }
  else
  {
    Serial.println("Failed!");
  }
  Serial.println("Setup End");
}
 
void loop() 
{
}