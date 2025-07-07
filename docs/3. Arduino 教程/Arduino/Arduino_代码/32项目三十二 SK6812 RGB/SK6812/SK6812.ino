/*  
 * 名称   : sk6812 RGB LED
 * 功能   : 打开sk6812 RGB LED
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <Adafruit_NeoPixel.h>
#define PIN 4
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{
  strip.begin();
  strip.show(); // 将所有像素点（灯）初始化为“off”，即关闭
}

void loop()
{
  // 显示颜色
  colorWipe(strip.Color(255, 0, 0), 50); // 红色
  colorWipe(strip.Color(0, 255, 0), 50); // 绿色 
  colorWipe(strip.Color(0, 0, 255), 50); // 蓝色
}

// 用一种颜色一个接一个地填充这些点
void colorWipe(uint32_t c, uint8_t wait) 
{
  for(uint16_t i=0; i<strip.numPixels(); i++) 
  {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}