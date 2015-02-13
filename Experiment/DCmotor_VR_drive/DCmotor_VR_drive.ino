int pwmpin = 10;
int val = 0;
void setup(){
  pinMode(pwmpin,OUTPUT);
}

void loop(){
  val = analogRead(A0) / 4;
  //analogWrite(pwmpin,0);
  analogWrite(pwmpin,val); 
  delay(15);
}


