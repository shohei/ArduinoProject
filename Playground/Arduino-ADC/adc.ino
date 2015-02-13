void setup(){
  Serial.begin(9600);
  Serial.println("Hello");
}

void loop(){
  int val = analogRead(A0);
  Serial.println(val);
  delay(1000);
}
