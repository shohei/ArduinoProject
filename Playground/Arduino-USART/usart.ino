void setup(){
  Serial.begin(9600);
  Serial.println("Hello");
}

void loop(){
  while(Serial.available()>0){
    char s = Serial.read();
    Serial.print(s);
  }
}

