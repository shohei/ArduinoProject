#include "SPI.h"

#define VCC  8
#define GND  9
#define SLAVE  10

void setup() {
#ifdef GND
  pinMode(GND, OUTPUT);
  digitalWrite(GND, LOW); 
#endif
#ifdef VCC
  pinMode(VCC, OUTPUT);
  digitalWrite(VCC, HIGH);
#endif
  pinMode(SLAVE, OUTPUT);
  digitalWrite(SLAVE, HIGH);

  Serial.begin(9600);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV4);
  SPI.setDataMode(SPI_MODE0);
}

void loop() {
  int value;

  delay(500);
  digitalWrite(SLAVE, LOW);        //  Enable the chip
  value = SPI.transfer(0x00) << 8;  //  Read high byte
  value |= SPI.transfer(0x00);      //  Read low byte
  digitalWrite(SLAVE, HIGH);         //  Disable the chip
  
  if ((value & 0x0004) != 0){
    Serial.println("Error");
  } else {
    Serial.println((value >> 3) * 0.25);
  }
}
