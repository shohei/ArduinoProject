void setup() { 
  Serial.begin(19200);
  delay(2000);
  String recv = "+CMTI: \"SM\",25";
  Serial.println(recv);
  String target = "+CMTI:";
  if(recv.startsWith(target)){
    Serial.println("The msg starts with "+target);    
  }
}

void loop() {

}
