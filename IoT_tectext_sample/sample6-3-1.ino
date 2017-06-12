const int ledPin = 13;//LEDピン番号(D13)
const int pirPin = 8;//RIPセンサの出力信号と接続するピン番号(D8)
void setup()//setup関数(初期化)
{
  pinMode(ledPin, OUTPUT);//ledPinの入出力モードを出力に設定
  pinMode(pirPin, INPUT);//pirPinの入出力モードを入力に設定　※省略可能
}

void loop()//roop関数
{
  int value = digitalRead(pirPin);//RIPセンサの出力を読み取る
  digitalWrite(ledPin, value);//読み取った値をledPinに書き込み
} 
