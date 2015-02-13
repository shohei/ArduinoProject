int pins[]={2,3,4,5};

void setup(){
  //initialization
  for(int i=0;i< sizeof(pins);i++){
    pinMode(pins[i],OUTPUT);  
    digitalWrite(pins[i],LOW);
  }
}


int dtime = 1000;
void loop(){
  digitalWrite(pins[0],HIGH);
  digitalWrite(pins[1],LOW);
  digitalWrite(pins[2],LOW);
  digitalWrite(pins[3],LOW);
  delay(dtime);

  digitalWrite(pins[0],LOW);
  digitalWrite(pins[1],LOW);
  digitalWrite(pins[2],HIGH);
  digitalWrite(pins[3],LOW);
  delay(dtime);

  digitalWrite(pins[0],LOW);
  digitalWrite(pins[1],HIGH);
  digitalWrite(pins[2],LOW);
  digitalWrite(pins[3],LOW);
  delay(dtime);

  digitalWrite(pins[0],LOW);
  digitalWrite(pins[1],LOW);
  digitalWrite(pins[2],LOW);
  digitalWrite(pins[3],HIGH);
  delay(dtime);
}
