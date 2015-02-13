#include <Gaussian.h>
double val;

void setup(){
  Serial.begin(9600);
  //Serial.println("\n\nStarting Random Gaussian Distribuition...");
  delay(20);
  randomSeed(analogRead(0));  
}

void loop(){
  Gaussian g1 = Gaussian(0, 1);
  val = g1.random();
  Serial.println(val);
  delay(1000);
}
