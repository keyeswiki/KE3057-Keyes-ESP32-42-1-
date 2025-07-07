/*  
 * 名称   : adjust the light
 * 功能   : 通过电位器控制LED的亮度
 * 作者   : http://www.keyes-robot.com/ 
*/
#define POT_PIN 34    // 电位器连接GPIO34 (ADC1_CH6)
#define LED_PIN 5     // LED连接GPIO5（支持PWM的引脚）

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  analogReadResolution(12);  // 设置ADC为12位精度（0-4095）
}

void loop() 
{
  // 1. 读取电位器值（12位ADC，0-4095）
  int potValue = analogRead(POT_PIN);
  
  // 2. 映射为LED的PWM占空比（8位：0-255）
  int pwmDuty = map(potValue, 0, 4095, 0, 255);
  
  // 3. 手动生成PWM信号控制LED
  manualPWM(LED_PIN, pwmDuty, 1000);  // 频率约1kHz
  
  // 4. 串口打印调试信息
  Serial.printf("Pot: %4d | PWM Duty: %3d\n", potValue, pwmDuty);
  delay(20);
}

// 手动PWM生成函数（不使用ledc）
void manualPWM(int pin, int duty, int freqHz) 
{
  int periodMicros = 1000000 / freqHz;          // 计算周期（微秒）
  int onTime = periodMicros * duty / 255;       // 计算高电平时间
  int offTime = periodMicros - onTime;          // 计算低电平时间
  
  digitalWrite(pin, HIGH);
  delayMicroseconds(onTime);
  digitalWrite(pin, LOW);
  delayMicroseconds(offTime);
}