#include <AFMotor.h>


AF_Stepper motor(200, 2);


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  motor.setSpeed(2000);  // 10 rpm   

  motor.step(100, FORWARD, SINGLE); 
  motor.release();
  delay(1000);
}

void loop() {
  //motor.step(10000, FORWARD, SINGLE); 
  //motor.step(100, BACKWARD, SINGLE); 
  //delay(1000);
  //motor.step(10000, FORWARD, DOUBLE); 
  //motor.step(100, BACKWARD, DOUBLE);
  //delay(1000);
  //motor.step(10000, FORWARD, INTERLEAVE); 
  //motor.step(100, BACKWARD, INTERLEAVE); 
  //delay(1000);
  motor.step(10000, FORWARD, MICROSTEP); 
  //motor.step(100, BACKWARD, MICROSTEP); 
  delay(1000);
}
