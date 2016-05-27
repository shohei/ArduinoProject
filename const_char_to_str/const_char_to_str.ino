void setup() {
  Serial.begin(19200);
  delay(1000);
  // put your setup code here, to run once:
  const char* ch = "hoge";
  Serial.println(ch);
  String moge = ch;
  Serial.println(moge);
}

void loop() {
  // put your main code here, to run repeatedly:

}
