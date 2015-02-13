#include <MsTimer2.h>

unsigned int rotPin=8;
unsigned int val;
unsigned int volt;
char msg[30];
float res;

int torq;
int mapped_torq;
int spd;
int spdMode=1;

#define DEBUG 1

int PWMpin[] ={
  2,3,4,5,6,7};
int command[6][6] = {
  {
    1,0,0,0,0,1  }
  ,
  {
    0,1,0,0,0,1  }
  ,
  {
    0,1,0,1,0,0  }
  ,
  {
    0,0,1,1,0,0  }
  ,
  {
    0,0,1,0,1,0  }
  ,
  {
    1,0,0,0,1,0  }
};
int current;
int stepHz;

void calcTorq(){
  Serial.print(" STATOR VOLT: ");
  Serial.print(mapped_torq);
}

void calcSpeed(){
  spd = analogRead(A2);  
//  spdMode = spd<200 ? 1 : 
//                (spd<400) ? 3 :
//                (spd<600) ? 5 :
//                (spd<800) ? 10 :
//                (spd<900) ? 20 :
//                (spd<1000) ? 30 : 100;

  spdMode = spd;
  Serial.print("STATOR SPEED: ");
  Serial.print(spdMode);
}

void dispRes(){
  calcSpeed();
  calcTorq();
  res = float(5)*float(volt)/float(255);
  sprintf(msg," ROTOR VOLT %.2f [V]",res);
  Serial.println(msg); 
}


void setup(){
  for(int i=0;i<6;i++){
    pinMode(PWMpin[i],OUTPUT); 
  }
  stepHz = 20;//1Hz  
  current=0;  

  pinMode(rotPin,OUTPUT);
  Serial.begin(9600);
  MsTimer2::set(1000,dispRes);
  MsTimer2::start();
}

void loop(){
  //stepHz = analogRead(A0); 
  //torq is to control output voltage
  torq = analogRead(A1);
  mapped_torq = map(torq,0,1023,0,255);  

  for(int i=0;i<6;i++){
    if(command[current][i]){
      analogWrite(PWMpin[i],mapped_torq);
      //digitalWrite(PWMpin[i],HIGH);
    }
    else{
      digitalWrite(PWMpin[i],LOW); 
    }
  }
  //delay(1000/stepHz);  
  delay(1000/spdMode);  
  current++;
  if(current>5)current=0;
  
  val = analogRead(A0);  
  volt = map(val,0,1023,0,255);
  analogWrite(rotPin,volt);

}


