#include <SPI.h>
 
char val = 'A';
 
void setup() {
   
  pinMode(10, OUTPUT);
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV32);
}
 
void loop() {
 
  digitalWrite(10, LOW);
  for(char i = 0; i < 4; i++) {
    SPI.transfer(val + i);
  }
  SPI.transfer('\r');
  digitalWrite(10, HIGH);  
 
  if(val++ > 0x58) {
    val = 'A';
  }
  delay(1000);
}
