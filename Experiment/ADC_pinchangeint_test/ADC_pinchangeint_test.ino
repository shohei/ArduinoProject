#include <PinChangeInt.h>

int keyPin = 0;

void setup(){
    
}

//13 pin
//A0 14
//A1 15

void loop(){
  attachInterrupt(0,flash,CHANGE);
  attachInterrupt(1,flash,CHANGE);
}
