#include "moge.h"

extern int hoge;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(hoge);
  delay(1000);
}
