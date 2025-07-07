/*
 * 名称   : Comprehensive experiment
 * 功能   : 多个传感器/模块协同工作
 * 作者   : http://www.keyes-robot.com/ 
*/
// RGB引脚定义
#define RED_PIN   32
#define GREEN_PIN 4
#define BLUE_PIN  2
#define POT_PIN 35    // 电位器

// 摇杆模块接口
int xyzPins[] = {33, 34, 18};   //x, y, z
// 避障传感器引脚
int Avoid = 14;
// LED引脚
#define PIN_LED   5
// 超声波传感器接口
int Trig = 13;
int Echo = 12;
// 按键引脚
int button = 23;
// 全局变量
int PushCounter = 0;
int yushu = 0;
unsigned long lastDebounceTime = 0;  // 上次按键状态变化时间
unsigned long debounceDelay = 50;    // 消抖延时(ms)
int lastButtonState = HIGH;          // 上次按键状态
int buttonState;                     // 当前按键状态

void setup() 
{
  Serial.begin(115200);
  // 初始化各引脚
  pinMode(xyzPins[0], INPUT);  // x轴
  pinMode(xyzPins[1], INPUT);  // y轴
  pinMode(xyzPins[2], INPUT_PULLUP);  // z轴按钮
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(button, INPUT_PULLUP);  // 使用内部上拉电阻
  pinMode(Avoid, INPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(PIN_LED, OUTPUT);
}

void loop() 
{
  // 读取按键状态（带消抖处理）
  int reading = digitalRead(button);
  
  // 检查按键状态是否变化
  if (reading != lastButtonState) 
  {
    lastDebounceTime = millis();
  }
  
  // 消抖处理
  if ((millis() - lastDebounceTime) > debounceDelay) 
  {
    // 如果按键状态与当前存储状态不同
    if (reading != buttonState) 
    {
      buttonState = reading;
      // 检测到按键按下（下降沿）
      if (buttonState == LOW)
      {
        PushCounter++;
        Serial.print("Button pressed. Mode: ");
        Serial.println(PushCounter % 5);
      }
    }
  }
  lastButtonState = reading;
  // 根据按键次数选择功能模式
  yushu = PushCounter % 5;
  switch(yushu) 
  {
    case 0:  // RGB随机颜色
      yushu_0();
      break;
    case 1:  // 避障传感器检测
      yushu_1();
      break;
    case 2:  // 摇杆值显示
      yushu_2();
      break;
    case 3:  // 电位器控制LED
      yushu_3();
      break;
    case 4:  // 超声波测距
      yushu_4();
      break;
  }
}

// RGB随机颜色
void yushu_0() 
{
  int r = random(256);
  int g = random(256);
  int b = random(256);
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
  delay(100);
}

// 避障传感器检测
void yushu_1() 
{
  int val = digitalRead(Avoid);
  Serial.print(val);
  if (val == 0) 
  {
    Serial.println("\tThere are obstacles");
  } 
  else 
  {
    Serial.println("\tAll going well");
  }
  delay(100);
}

// 摇杆值显示
void yushu_2() 
{
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);
  Serial.println("X,Y,Z: " + String(xVal) + ", " + String(yVal) + ", " + String(zVal));
  delay(100);
}

// 电位器控制LED
void yushu_3() 
{
  int potValue = analogRead(POT_PIN);
  int pwmDuty = map(potValue, 0, 4095, 0, 255);
  analogWrite(PIN_LED, pwmDuty);
  Serial.println("Potentiometer: " + String(potValue) + " -> PWM: " + String(pwmDuty));
  delay(100);
}

// 超声波测距
void yushu_4() 
{
  float distance = checkdistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
}

// 超声波测距函数
float checkdistance() 
{
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  float distance = pulseIn(Echo, HIGH) / 58.00;
  delay(10);
  return distance;
}