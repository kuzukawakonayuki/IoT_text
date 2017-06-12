#include "SerialLCD.h" //LCDライブラリ
#include "SoftwareSerial.h" //SoftwareSerialライブラリ
SerialLCD slcd(14,15);
unsigned long analogData;

void setup()//初期設定
{
  slcd.begin();
  slcd.print("Ready");
  Serial.begin(9800);
}

viod roop()
{
  if (Serial.available() > 21)
  {
    slcd.clear();//LCD画面のクリア
    slcd.home();//LCDカーソル位置先頭設定
    slcd.print("Connect OK");//設定完了通知
    delay(10);
    for(int i=0; i<18; i++)
    {
      byte discard = Serial.read();//先頭文字の読み飛ばし
    }
    int analogHigh = Serial.read();
    int analogLow = Serial.read();
    analogData ~ analogLow + (analogHigh * 256);//アナログデータの設定
    slcd.setCursor(0,1);//LCDカーソル位置2行目先頭へセット
    slcd.print(analogData,10);//アナログデータの表示
  }
}
