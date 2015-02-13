//#include <MsTimer2.h>
#include <FlexiTimer2.h>
volatile int iCount;
void counting() {
  iCount++;
  if (iCount==960) {
    iCount = 0;
  }
}
void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT);  //oc0a (PD6) for X
  pinMode(5, OUTPUT);  //oc0b (PD5) for Y
  pinMode(9, OUTPUT);  //oc1a (PB1) for /X
  pinMode(10, OUTPUT);  //oc1b (PB2) for /Y
  iCount = 0;  
  //MsTimer2::set(1, counting); // 100ms period
  //MsTimer2::start();
  FlexiTimer2::set(1,1.0/5,counting); // 100ms period
  FlexiTimer2::start();
}
void loop() {
  int iReadtimer;
  int iStep_rot;
  int iStep;
  int iVar;
  int iOut_a;
  int iOut_b;  
  iReadtimer = iCount;  //read timer from counter
  iStep_rot = iReadtimer / 10;  //step count
  iStep = iStep_rot % 4;  //step no (0..3)
  iVar = iReadtimer % (iStep_rot * 10); //variation in the step (0..9)
  if (iVar <= 4) {
    iOut_a = 255;  //output data B
    iOut_b = 255*iVar/5;  //output data A
  }else {
    iOut_a = 255 - ((iVar-5)*255/5);  //output data B
    iOut_b = 255  ;  //output data A
  }
  switch (iStep) {
    case 0:
      analogWrite(6, iOut_a);
      analogWrite(5, iOut_b);
      analogWrite(9, 0);
      analogWrite(10, 0);
      break;
    case 1:
      //analogWrite(6, 0);
      digitalWrite(6,LOW);
      analogWrite(5, iOut_a);
      analogWrite(9, iOut_b);
      analogWrite(10, 0);
      break;
    case 2:
      //analogWrite(6, 0);
      //analogWrite(5, 0);
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      analogWrite(9, iOut_a);
      analogWrite(10, iOut_b);
      break;
    case 3:
      analogWrite(6, iOut_b);
      //analogWrite(5, 0);
      digitalWrite(5,LOW);
      analogWrite(9, 0);
      analogWrite(10, iOut_a);
    default:
      break;
  }
  Serial.print(iStep);
  Serial.print(iOut_b);
  Serial.println(iOut_a);
  
}
