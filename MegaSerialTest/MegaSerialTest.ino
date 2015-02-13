#include <avr/io.h>
#include <util/delay.h>
#include "usart.h"

int main(void){
  //Serial.begin(9600);
  //Serial.println("Hello, Mega.");
  int ubrr = Usart::getUBRR(9600);  
  Usart::USART_init(ubrr);  
  Usart::putString("Hello\n");  

  DDRB |= _BV(PORTB7);

  while(1){
    PORTB ^= _BV(PORTB7);  
    _delay_ms(1000);
  }


  return 0; 
}
//void setup(){
//  Serial.begin(9600);
//  Serial.println("Hello, Mega.");
//}
//
//void loop(){
//
//}

