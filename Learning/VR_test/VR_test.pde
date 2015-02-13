int analogpin = 0;
int analogValue;
void setup(){
  Serial.begin(9600);
}

void loop(){
  analogValue = analogRead(analogpin);  
  Serial.print(analogValue);
  delay(100);
}
