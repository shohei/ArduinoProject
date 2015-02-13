#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define DD_MOSI     PINB3          // Master out - Slave in pin
#define DD_MISO     PINB4          // Master in - Slave out pin
#define DD_SCK      PINB5          // Clock from master
#define DDR_SPI     PORTB          // DDR_SPI

char arr[] = {'a','b','c','d','e','f','g','h'};

int main(void){
  Serial.begin(9600);
  sei();

  Serial.println("Hello, Uno Master.");
  
  SPI_MasterInit();
  for(int i=0;i<7;i++){
    Serial.print("writing ");
    Serial.println(arr[i]);
    SPI_MasterTransmit(arr[i]);
  }

  for(;;){
  }

  return 0;  
}

void SPI_MasterInit(void){
  DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK); 
  SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void SPI_MasterTransmit(char cData){
  SPDR = cData; 
  while(!(SPSR&(1<<SPIF)))
   ;
}

