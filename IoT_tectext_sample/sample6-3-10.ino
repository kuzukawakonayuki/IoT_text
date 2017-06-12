//3G通信module+ArduinoMega
//M2Xへのセンサ値アップロード
#define iemSerial Serial1
const unsigned long baudrate = 9600;
#define LIMITTIME 35000 //ms (3g module strat time)
//インターネット接続でのURL,ヘッダ,ボディ,の設定
String URL = "http://api-m2x.att.com/vs/devices/your_devices_key/updaes/";
String HEADER = "\"Host: api-m2x.att.com$r$nX-M2X-KEY:<M2X_Key>$r$nContent-Type:application/json$r$n\"";
String BODYs = "\"{\$\"values\$\":{\$\"";
String BODYe = "\$\":[{\$\"timestamp\$\":\$\"";

void setup()
{
  Serial.begin(baudrate);
  Serial.println(">Ready. Initilaizing...");
  pinMode(7,OUTPUT); digitalWrite(7,HIGH);
  delay(100); digitalWrite(7,LOW);//3GIMのシールド電源ON
  while(!_3Gsetup()); Serial.println("Connected");//3GIM初期接続
  pinMode(A0,OUTPUT);
  pinMode(A2,OUTPUT); digitalWrite(A2,HIGH);
}

void loop()
{
  String dtime = datetime();//時間取得
  unsigned long time = millis();//時間設定
  int light = analogRead(A1);//TABShield light sensor
  Serial.println("Light = " + String(light));//光センサをシリアル画面に表示する

  //--------以下M2Xにデータアップロード--------

  //データアップに成功した場合
  if(_3G_WP("$WP" + URL + BODYs + "LIGHT" + BODYe + dtime + "\$\",\$\"value\$\":\$\"" + String(light) + "\$\"}]}}\" " + HEADER))
  {
    Serial,println("Data Update compilete:" + iemSerial.readStringUntil("\n"));
  }
  else//データアップに失敗した場合
  {
    Serial.println("Data Update false...");
    while(millis() - tim<60000):
    {
      //1分間待機する
    }
  }
}
