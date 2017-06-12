String std=Serial.readStringUntil('\n');
if(str.length()>47)
{
  String sval = str.substring(37,47);//アナログセンサ値の文字列取得
  sval.toCharArray(pr, 10);//配列文字データ変換

  //以下アナログデータの変換式
  int val1 = (pr[2] - ((pr[2] > '9')?('A' - 10):'0')) * 16 + pr[3] - ((pr[3] > '9')?('A' - 10):'0');
  int val2 = (pr[9] - (pr[9] < 'A')?'0':'A' - 10);

  //光センサ読み取り
  int lgt = val1 * 4 + (val2/4);
}
