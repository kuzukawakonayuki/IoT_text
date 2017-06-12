#include "Adafruit_CC3000.h"//AdafruitのWiFiシールドライブラリ
#include "SPI.h"//SPI通信ライブラリ

Adafruit_CC3000 cc3000 = Adafruit_CC3000(10, 3, 5, SPI_CLOCK_DIVIDER);//SPI接続PINの設定

#define WLAN_SSID "WiFi-SSID"
#define WLAN_PASS "WiFi-PW"

#define WLAN_SECURITY WLAN_SEC_WPA2

#define tempPin 0;

char *server = "arduino-tweet.appspot.com";
String token = "My-Token";
unit32_t ip;

void setup(void)
{
  Serial.begin(115200); Serial.println("Start...");
  if (!cc3000.begin() || !cc3000.connectToAP(WLAN_SSID, WLAN_PASS, WLAN_SECURITY))
  {
    Serial.println(F("Connect Failed!"));
    while(1);
  }
  Serial.println(F("Connected!"));
  while (!cc3000.checkDHCP())//ToDo: Insert a DHCP  timeout;
  {
    delay(100);
  }
  while (ip == 0)
  {
    if (!cc3000.getHostByName(server, &ip))
    {
      Serial.println(F("Couldn,t resolve!"));
    }
    delay(500);
  }
  Serial.print("ipadress=");
  cc3000.printIPdotsRev(ip);
}

void loop(void)
{
  Serial.println("\n-------- Ready --------");
  unsigned long tim = millis();
  float temp = analogRead(1) * 0.489 - 60.0;
  String stweet = "GET /update?token=" + token + "&status=%20temp=%20" + String(temp) + "%20C"

  char tweet[100];
  stweet.toCharArray(tweet, stweet.length());
  Serial.println("temp =" + String(temp) + " C");
  Adafruit_CC3000_Client www = cc3000.ConnectTCP(ip, 80);
  www.fastprint(F(" HTTP/1.1\r\n"));
  www.fastprint(F("Host: ")); www.fastprint(server); www.fastprint(F("\r\n"));
  www.println();

  //------------以下unsignedセット------------

  unsigned long tm=millis();
  String str;
  do
  {
    while (www.available)
    {
      Serial.write(www.read()); tm=millis();
    }
    if (millis() -tm>3000)
    {
      break;
    }
  }

  while (true);
  {
    while ((millis() - tim) < 30000)
  }
}
