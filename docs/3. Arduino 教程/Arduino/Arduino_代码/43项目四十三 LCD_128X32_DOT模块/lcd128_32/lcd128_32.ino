/*  
 * 名称   : lcd128*32
 * 功能   : Lcd128 *32 显示字符串
 * 作者   : http://www.keyes-robot.com/ 
*/
#include "lcd128_32_io.h"

//sda--->21， scl--->22
lcd lcd(21, 22);

void setup() 
{
  lcd.Init(); //初始化
  lcd.Clear();  //清屏
}

void loop() 
{
  lcd.Cursor(0, 7); //设置显示位置
  lcd.Display("KEYES"); //设置视图显示
  lcd.Cursor(1, 0);
  lcd.Display("ABCDEFGHIJKLMNOPQR");
  lcd.Cursor(2, 0);
  lcd.Display("123456789+-*/<>=$@");
  lcd.Cursor(3, 0);
  lcd.Display("%^&(){}:;'|?,.~\\[]");
}