#include "Wire.h"//Wireライブラリ(標準)
#include "SHT2x.h"//SHT2xライブラリ

void setup()//setup関数(初期化)
{
  Wire.begin();
  Serial.begin(9600);
}

void roop()
{
  Serial.print(",temperature(C): ");
  Serial.print(SHT2x.GetTemperature());//温度を取得して出力
  Serial.print("Humidity(%): ");
  Serial.println(SHT2x.GetHumidity());//湿度を取得して出力改行
  delay(1000);
}
