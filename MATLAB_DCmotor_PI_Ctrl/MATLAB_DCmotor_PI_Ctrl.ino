#include "TimerOne.h"

int val;
int mval;
int mvol;
int vol;
int Kp = 4;
int Ki = 16;
int ctrl_val=0;
int target_val;
float pval;
float ival;
float err;
int dt=10;

void setup() {
  pinMode(9,OUTPUT);
  Serial.begin(9600);
  Timer1.initialize(500000);
  Timer1.attachInterrupt(debugCallback);
}

void debugCallback(){
  vol = analogRead(5);
  mvol = map(vol,0,1023,0,255);
  Serial.print("Target: ");
  Serial.print(target_val);
  Serial.print(", error: ");
  Serial.print(err);
  Serial.print(", output: ");
  Serial.println(mvol);
}

void loop() {
  val = analogRead(0);
  target_val = map(val,0,1023,0,255);
  err = float(target_val) - float(ctrl_val);
  pval = float(Kp) * err;
  ival = ival + float(Ki) * err;
  ctrl_val = (int) (pval+ival);
  analogWrite(9,ctrl_val);
  delay(dt);  
}

