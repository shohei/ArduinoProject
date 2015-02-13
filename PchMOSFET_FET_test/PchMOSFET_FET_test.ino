#include <MsTimer2.h>

int val;
int mapval;

void disp(){
  Serial.println(mapval);
}

void setup(){
  pinMode(9,OUTPUT);  
  Serial.begin(9600);
  MsTimer2::set(1000,disp);
  MsTimer2::start();
}

void loop(){
  val = analogRead(A0);
  mapval = map(val,0,1023,0,255);
  analogWrite(9,mapval); 
}

