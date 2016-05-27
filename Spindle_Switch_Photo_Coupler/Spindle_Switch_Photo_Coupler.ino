/* 
---->	http://www.adafruit.com/products/1438
*/
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz  
  AFMS.begin();
  myMotor->setSpeed(0);
  myMotor->run(FORWARD); 
}

void loop() {
  Serial.println("ON");
  myMotor->setSpeed(250);  
  delay(3000);
  Serial.println("OFF");
  myMotor->setSpeed(0);  
  delay(3000);
}
