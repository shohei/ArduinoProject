
//char* charac[11];
//char incoming;

int swPin = 12;
int mPin = 13;

int RTS_pin = 2;
int CTS_pin = 3;

int finished = 0;

void setup(){
  Serial.begin(9600); 
  pinMode(swPin,INPUT);
  pinMode(mPin,OUTPUT);
  pinMode(RTS_pin,INPUT);
  pinMode(CTS_pin,OUTPUT);
}

void loop(){
  if(finished == 0) {
  //if(Serial.available()){
 //Serial.print("Hello, world!"); 
 //delay(1000);
  //incoming = Serial.read();
  //Serial.print(incoming);

  /*
  int val = digitalRead(swPin);

  if(val == HIGH) {
  digitalWrite(mPin,HIGH);
  
  digitalWrite(CTS_pin,HIGH);
  */
  
  //prevent the miss sending
  delay(2000);
  //char* charac[] = {"PA;","PA;","VS4;","!VZ4;","!MC1;","!PZ0,20;","PU0,0;","PD190,0;","PD190,190;","PD0,190;","!MC0;"};
  char* charac[] = {"P","A",";","P","A",";","V","S","4",";","!","V","Z","4",";","!","M","C","1",";","!","P","Z","0",",","2","0",";","P","U","0",",","0",";","P","D","1","9","0",",","0",";","P","D","1","9","0",",","1","9","0",";","P","D","0",",","1","9","0",";","!","M","C","0",";"};

  int charac_num = sizeof charac /sizeof charac[0];
  digitalWrite(mPin,HIGH);
  for(int i=0;i<charac_num;++i) {
    // int status = digitalRead(RTS_pin);
    // while(status == LOW){
    //   digitalWrite(CTS_pin,LOW);
    //   status = digitalRead(RTS_pin);
    //   digitalWrite(mPin,LOW);
    //}
      digitalWrite(mPin,HIGH);
      digitalWrite(CTS_pin,HIGH);
      Serial.write(charac[i]);
      delay(100);     
  }   

  digitalWrite(mPin,LOW);

  //Serial.write("PA;PA;VS4;!VZ4;!MC1;!PZ0,20;PU0,0;PD190,0;PD190,190;PD0,190;!MC0;");

  //Serial.write("50413b50413b5653343b21565a343b214d43313b21505a302c32303b5055302c303b50443139302c303b50443139302c3139303b5044302c3139303b214d43303b");  
  finished = 1;
  //}

  //digitalWrite(CTS_pin,HIGH);
//  while(val == HIGH){
      //}
//    }
//   digitalWrite(mPin,LOW);
 }

}

