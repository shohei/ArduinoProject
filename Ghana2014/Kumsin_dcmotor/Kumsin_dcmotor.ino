int speedPin = 11;
int mPin1 = 12;
int mPin2 = 13;

void setup(){
 pinMode(speedPin,OUTPUT); 
 pinMode(mPin1,OUTPUT); 
 pinMode(mPin2,OUTPUT); 
}

void loop(){
  analogWrite(speedPin,255);
  digitalWrite(mPin1,HIGH);
  digitalWrite(mPin2,LOW);
  delay(3000);

  analogWrite(speedPin,180);
  digitalWrite(mPin1,HIGH);
  digitalWrite(mPin2,LOW);
  delay(3000);

  analogWrite(speedPin,120);
  digitalWrite(mPin1,HIGH);
  digitalWrite(mPin2,LOW);
  delay(3000);

  //CW(1000);
  //motor_break(100);
  //CCW(1000);
}


void CW(int msec){
  digitalWrite(mPin1,HIGH); 
  digitalWrite(mPin2,LOW);
  delay(msec);
}

void CCW(int msec){
  digitalWrite(mPin1,LOW); 
  digitalWrite(mPin2,HIGH);
  delay(msec);  
}

void motor_break(int msec){
  digitalWrite(mPin1,HIGH);
  digitalWrite(mPin2,HIGH);
  delay(msec);
}


