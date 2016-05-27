#include <SoftwareSerial.h>

SoftwareSerial mySerial(7, 8);

void setup() {
 // put your setup code here, to run once:
  mySerial.begin(19200);               // the GPRS baud rate
  Serial.begin(19200);    // the GPRS baud rate
  while(!mySerial){
    //wait soft serial initialization
  }
  while (!Serial) {
    // wait serial port initialization
  }
  Serial.println("SoftSerial and Serial initialized.");
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  mySerial.println("heartbeating...");
  while(Serial.available()!=0){
    Serial.write(Serial.read());
  }
  delay(3000);
}
