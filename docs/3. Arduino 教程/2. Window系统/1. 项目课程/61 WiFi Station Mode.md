# 第六十一课 WiFi Station Mode

## 1.1 项目介绍

ESP32有3种不同的WiFi工作模式：

- Station模式（作为WiFi设备主动连接路由器，也叫做WiFi Client）
- AP模式（作为一个Access Point，让其他WiFi设备来连接）即WiFi热点
- Station+AP共存模式（ESP32连接路由器的同时自身也是一个热点供其他WiFi设备来连接）

所有WiFi编程项目在使用WiFi前必须配置WiFi运行模式，否则无法使用WiFi。在这节实验课程中，我们将学习使用ESP32的WiFi Station模式。

**Station 模式：**

当ESP32选择Station模式时，它作为一个WiFi客户端。它可以连接路由器网络，通过WiFi连接与路由器上的其他设备通信。如下图所示，PC和路由器已经连接，ESP32如果要与PC通信，需要将PC和路由器连接起来。

<img src="media/611101.png" style="zoom:80%;" />

---

## 1.2 实验组件

| ![img](media/KS5016.png) | ![img](media/USB.jpg) |
| ------------------------ | --------------------- |
| ESP32 Plus主板 x1        | USB线  x1             |

---

## 1.3 模块接线图

![](media/011301.png)

---

## 1.4 实验代码

本项目中使用的代码保存在文件夹“<u>**3. Arduino教程\2. Windows 系统\1. 项目课程\代码**</u>”中，我们可以在此路径下打开代码文件''**WiFi_Station_Mode.ino**"。

路由器的SSID是无线网的无线名称。SSID是 ServiceSetldentifier 的缩写，意思是:服务集标识。SSID技术可以将一个无线局域网分为几个需要不同身份验证的子网络，每一个子网络都需要独立的身份验证，只有通过身份验证的用户才可以进入相应的子网络，防止未被授权的用户进入本网络。所以在代码运行之前，需要配置 WiFi 名称和密码，将其修改为你自己使用的WiFi 名称和密码，如下图所示。

![](media/611401.png)

```c++
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
```

ESP32主板通过USB线连接到计算机后开始上传代码。为了避免将代码上传至ESP32主板时出现错误，必须选择与计算机连接正确的控制板和串行端口。

点击“**<u>工具</u>**”→“**<u>开发板</u>**”，可以查看到各种不同型号ESP32开发板，选择对应的ESP32开发板型号。

点击“<u>**工具**</u>”→“**<u>端口</u>**”，选择对应的串行端口。

**注意：将ESP32主板通过USB线连接到计算机后才能看到对应的串行端口**。

单击![img](media/wps17.jpg)将代码上传到ESP32主控板，等待代码上传成功后查看实验结果。

---

## 1.5 实验结果

代码上传成功后，打开串口监视器，设置波特率为**<u>115200</u>**。

开始连接，串口监视器打印出“**<u>Connecting to ChinaNet_2.4G</u>**” 提示正在连接到路由器的SSID，当ESP32成功连接到路由器的 SSID 时，串行监视器将打印出 WiFi 分配给ESP32的**<u>IP地址</u>**。

![img](media/611501.png)

**注意：如果打开串口监视器且设置好波特率，串口监视器窗口还是没有显示任何信息，可以尝试按下ESP32的RESET按键。**

![RESET](media/RESET.jpg)

---

## 1.6 代码说明

| 代码                                     | 说明                                                         |
| ---------------------------------------- | ------------------------------------------------------------ |
| WiFi.begin(ssid_Router, password_Router) | 连接初始化连接。ssid_Router为 WiFi 名称，password_Router为连接 WiFi 所用的密码。 |
| WiFi.status()                            | 调用完成后，wifi并不会立即就连接上。此接口函数的作用就是检查wifi是否已经连接上。当返回值为WL_CONNECTED时表示已经连接上。该函数还有其它返回值，表示wifi连接失败等情况。 |
| WiFi.localIP()                           | 显示本机ip。                                                 |

 
