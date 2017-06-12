const int tempPin = 0;//温度センサとピン番号(A0接続)

//setup関数(初期化)
void setup() {
  Serial.begin(9600);//Serial通信を9600bpsで行う
}

//roop関数
void roop (){
  int mV = analogRead(tempPin) * 4.89;//tempPinの電圧を取得
  float temperature = (mV - 600) / 10;//電圧から温度へ変換
  Serial.println(temperature);//temperatureを出力改行
  delay(1000);//ウェイト1000ms
}
