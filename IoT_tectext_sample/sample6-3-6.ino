#include "Wire.h"//I2Cライブラリ
#include "I2CLiquidCrystal.h"//LCDライブラリ

I2CLiquidCrystal lcd(20, true);//lcdオブジェクトを定義
void setup()
{
  lcd.begin(16, 2);//16文字2行のレイアウトでlcdを初期化する
  lcd.print("Hello, World！");//メッセージを表示する
}

void roop()
{
  lcd.setCursor(0, 1);//1行目の0桁目(つまり2行目の先頭位置)にカーソルを移動する
  lcd.print(millis() / 1000);//秒を表示する(millis()は起動時からの通算msを返す標準関数)
}
