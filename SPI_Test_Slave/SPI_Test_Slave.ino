#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define DD_MOSI     PINB3          // Master out - Slave in pin
#define DD_MISO     PINB4          // Master in - Slave out pin
#define DD_SCK      PINB5          // Clock from master
#define DDR_SPI     PORTB          // DDR_SPI

char rcvData;

void SPI_SlaveInit(void){
  DDR_SPI = (1<<DD_MISO); 
  SPCR = (1<<SPE);
}

int main(){
  Serial.begin(9600);
  Serial.println("Hello, Uno Slave.");

  SPI_SlaveInit();
  sei();

  for(;;){

  }

  return 0;  
}


char SPI_SlaveReceive(void){
  //while(!(SPSR&(1<<SPIF)));
  return SPDR; 
}


ISR (SPI_STC_vect)                  // SPI interrupts
{
  rcvData = SPI_SlaveReceive();  // receive and store byte
  Serial.print("Received: ");
  Serial.println(rcvData);
}

