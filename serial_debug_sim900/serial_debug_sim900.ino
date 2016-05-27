void setup(){
  Serial.begin(19200);
}

void loop(){
  if(gprs.available()){
    Serial.write(gprs.read());
  }
  if(Serial.available()){     
    gprs.write(Serial.read()); 
  }
}

