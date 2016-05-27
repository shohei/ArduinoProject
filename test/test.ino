void setup() {
 Serial.begin(9600);
 pinMode(10,OUTPUT);
}

void loop() {
  int val = analogRead(A0);
  Serial.println(val);
  int c = map(val,0,1023,0,255);
  analogWrite(10,c);
  delay(20);
}
