#include "mbed.h"
DigitalOut myLed(LED1);//LED1ピンをデジタル出力ピンmyLedとする
int main()
{
  while (1)
  {
    myLed = 1;//myLedに1を書き込み、LED1を点灯させる
    wait(0.5);//0.5秒待機
    myLed = 0;//myLedに0を書き込み、LED1を消灯させる
    wait(0.5);
  }
}
