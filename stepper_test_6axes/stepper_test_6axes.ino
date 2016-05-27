#include <Arduino.h>
#include "DRV8825.h"

// using a 200-step motor (most common)
// pins used are DIR, STEP in that order
DRV8825 stepper1(200, 62, 63);//X
DRV8825 stepper2(200, 64, 65);//Y
DRV8825 stepper3(200, 66, 67);//Z
DRV8825 stepper4(200, 28, 36);//XX
DRV8825 stepper5(200, 41, 43);//YY
DRV8825 stepper6(200, 47, 32);//ZZ

int enablePins[] = {48,46,44,42,39,45};
// int outPins[] = {62,63,64,65,66,67,28,36,41,43,47,32}; 

void enableAllStepper(){
	for(int i=0;i<6;i++){
	  pinMode(enablePins[i],OUTPUT);
	  digitalWrite(enablePins[i],LOW);
      Serial.print("stepper");
      Serial.print(i+1);
      Serial.println(" enabled");
	}
  //   for(int i=0;i<12;i++){
  //     pinMode(outPins[i],OUTPUT);
  // }
}

void setup() {
	Serial.begin(9600);
	delay(500);
	Serial.println("enable all drivers.");
	enableAllStepper();
    // Set target motor RPM to 1RPM
    stepper1.setRPM(60);
    stepper2.setRPM(60);
    stepper3.setRPM(60);
    stepper4.setRPM(60);
    stepper5.setRPM(60);
    stepper6.setRPM(60);
    // Set full speed mode (microstepping also works for smoother hand movement
    stepper1.setMicrostep(32);
    stepper2.setMicrostep(32);
    stepper3.setMicrostep(32);
    stepper4.setMicrostep(32);
    stepper5.setMicrostep(32);
    stepper6.setMicrostep(32);
}

void loop() {
    // testDrive();
    

    
}


void testDrive(){
    Serial.println("step X");
    stepper1.rotate(360);
    Serial.println("step Y");
    stepper2.rotate(360);
    Serial.println("step Z");
    stepper3.rotate(360);
    Serial.println("step XX");
    stepper4.rotate(360);
    Serial.println("step YY");
    stepper5.rotate(360);
    Serial.println("step ZZ");
    stepper6.rotate(360);
}