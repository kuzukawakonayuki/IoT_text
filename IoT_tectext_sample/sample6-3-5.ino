#include "Servo.h"//Servoライブラリ(標準)
const int servoPin = 9;//サーボモータの制御信号を接続するピン番号(D9)
Servo myservo;//Servoオブジェクトを定義
int position = 0;//サーボの現在回転ポジションをセット
void setup()
{
  myservo.attach(servoPin);//サーボmyservoも制御信号をservoPinとして初期化
}

void roop()
{
  for(position = 0; position <= 180; position += 1)//1°づつ右回転させる
  {
    myservo.write(position);
    delay(15);
  }

  for(position = 180; position >= 0; position -= 1)//1°づつ左回転させる
  {
    myservo.write(position);
    delay(15);
  }
}
