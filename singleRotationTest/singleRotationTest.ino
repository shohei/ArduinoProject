#include <Arduino.h>
#include "DRV8825.h"

DRV8825 stepper1(200, 62, 63);//X

void setup() {
  // put your setup code here, to run once:
    pinMode(48,OUTPUT);
    digitalWrite(48,LOW);
    stepper1.setRPM(300);
    stepper1.setMicrostep(32);
}

void loop() {
  // put your main code here, to run repeatedly:
  stepper1.rotate(1000);
  delay(2000);
  stepper1.rotate(-1000);
  delay(2000);  
}
