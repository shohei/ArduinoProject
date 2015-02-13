int val; //読み取り値の変数を用意

void setup(){
  Serial.begin(9600);
}
void loop(){
    val=analogRead(0);
    Serial.write(val);
    //1秒間に20回ループ(0.05sec)とする
    delay(500);
  }
}
