/*  
 * 名称   : sk6812 RGB LED
 * 功能   : 打开sk6812 RGB LED
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <Adafruit_NeoPixel.h>

#define PIN 4

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // 将所有像素点（灯）初始化为“off”，即关闭
}

void loop() {
  // 显示颜色
  colorWipe(strip.Color(255, 0, 0), 50); // 红色
  colorWipe(strip.Color(0, 255, 0), 50); // 绿色 
  colorWipe(strip.Color(0, 0, 255), 50); // 蓝色
  // 剧院像素追逐
  theaterChase(strip.Color(127, 127, 127), 50); // 白色 
  theaterChase(strip.Color(127,   0,   0), 50); // 红色
  theaterChase(strip.Color(  0,   0, 127), 50); // 蓝色

  rainbow(20);
  rainbowCycle(20);
  theaterChaseRainbow(50);
}

// 用一种颜色一个接一个地填充这些点
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// 与上面略有不同，用像彩虹一样的颜色均匀分布在各处
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//剧院式的爬行灯，也叫跑马灯
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //做10个循环的追逐
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //每三个像素打开一次
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //每三个像素关闭一次
      }
    }
  }
}

//带有彩虹效果的剧院式爬行灯
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // 在轮盘上循环所有256种颜色
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //每三个像素打开一次
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //每三个像素关闭一次
        }
    }
  }
}

// 输入0到255的值来获取颜色值。
// 颜色从r -> g -> b 再回到r的过渡
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}