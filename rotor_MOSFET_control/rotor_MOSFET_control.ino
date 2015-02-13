#include <MsTimer2.h>

unsigned int rotPin=8;
unsigned int val;
unsigned int volt;
char msg[30];
float res;

void dispRes(){
  res = float(5)*float(volt)/float(255);
  //Serial.println(res);
  sprintf(msg,"reading %d : output %.2f [V]",val,res);
  Serial.println(msg); 
}

void setup(){
  pinMode(rotPin,OUTPUT);
  Serial.begin(9600);
  MsTimer2::set(1000,dispRes);
  MsTimer2::start();
}

void loop(){
  val = analogRead(A0);  
  volt = map(val,0,1023,0,255);
  analogWrite(rotPin,volt);
}

