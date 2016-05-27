void setup() {
  Serial.begin(9600);
  delay(1000); 
}

void loop() {
  if(Serial.available()){
    switch(Serial.read()){
      case 'a':
        Serial.println("received a");
        break;      
    }
  }
}
