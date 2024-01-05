/*
 * 名称   : Comprehensive experiment
 * 功能   : 多个传感器/模块协同工作
 * 作者   : http://www.keyes-robot.com/ 
*/
//RGB连接到2,4,32
int ledPins[] = {2, 4, 32};    //定义红色，绿色，蓝色引脚
const byte chns[] = {0, 1, 2}; //定义PWM通道
int red, green, blue;

//摇臂模块接口
int xyzPins[] = {33, 34, 18};   //x, y, z

//电位器引脚连接到端口35
int resPin = 35;

//避障传感器引脚连接到IO端口14
int Avoid = 14;

//LED连接到GP5
#define PIN_LED   5  // LED的引脚
#define CHAN    3    // ledc 3

//超声波传感器接口
int Trig = 13;
int Echo = 12;

//关键模块端口
int button = 23;

int PushCounter = 0;//存储键被按下的次数
int yushu = 0;
unsigned char dht[4] = {0, 0, 0, 0};//只接收数据的前32位，不接收奇偶校验位
bool ir_flag = 1;
float out_X, out_Y, out_Z;

void counter() {
  delay(10);
  ir_flag = 0;
  if (!digitalRead(button)) {
    PushCounter++;
  }
}

void setup() {
  Serial.begin(9600);//波特率设置为9600
  pinMode(xyzPins[0], INPUT); //x axis. 
  pinMode(xyzPins[1], INPUT); //y axis. 
  pinMode(xyzPins[2], INPUT_PULLUP);   //Z轴是一个按钮
  ledcSetup(CHAN, 1000, 12);
  ledcAttachPin(PIN_LED, CHAN);
  pinMode(button, INPUT);//关键模块
  attachInterrupt(digitalPinToInterrupt(button), counter, FALLING);  //外部中断0，下降沿触发
  pinMode(Avoid, INPUT);//避障传感器
  pinMode(Trig, OUTPUT);//超声波警报器
  pinMode(Echo, INPUT);
  for (int i = 0; i < 3; i++) {   //设置pwm通道，1KHz,8bit
    ledcSetup(chns[i], 1000, 8);
    ledcAttachPin(ledPins[i], chns[i]);
  delay(1000);
 }
}

void loop() {
  yushu = PushCounter % 5;
  if (yushu == 0) {  //余数为0
    yushu_0();  //rgb显示
  } else if (yushu == 1) {  //余数是1
    yushu_1();  //避障传感器检测障碍物
  } else if (yushu == 2) {  //余数是2
    yushu_2();  //显示摇杆值
  } else if (yushu == 3) {  //余数是3
    yushu_3();  //显示电位器ADC值和电位器控制LED
  } else if (yushu == 4) {  //余数是4
    yushu_4();  //显示超声波检测到的距离
  } 
}

//RGB
void yushu_0() {
  red = random(0, 256);
  green = random(0, 256);
  blue = random(0, 256);
  setColor(red, green, blue);
  delay(200);
}
void setColor(byte r, byte g, byte b) {
  ledcWrite(chns[0], 255 - r); 
  ledcWrite(chns[1], 255 - g);
  ledcWrite(chns[2], 255 - b);
}

void yushu_1() {
  int val = digitalRead(Avoid);//读取避障传感器的数字电平输出
  Serial.print(val);//串口打印值
  if (val == 0) {//障碍物检测
    Serial.println("   There are obstacles");
  }
  else {//未发现障碍物
    Serial.println("   All going well");
  }
  delay(100);
}

void yushu_2() {
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);
  Serial.println("X,Y,Z: " + String(xVal) + ", " +  String(yVal) + ", " + String(zVal));
  delay(500);
}

void yushu_3() {
  int adcVal = analogRead(resPin); //读adc
  Serial.println(adcVal);
  int pwmVal = adcVal;     //adcVal重新映射到pwmVal
  ledcWrite(CHAN, pwmVal); //设置累计脉冲宽度
  delay(100);
}

void yushu_4() {
  float distance = checkdistance();
  Serial.print("distance:");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
}

float checkdistance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  float distance = pulseIn(Echo, HIGH) / 58.00;
  delay(10);
  return distance;
}