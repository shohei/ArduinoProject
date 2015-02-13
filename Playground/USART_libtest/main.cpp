#include "usart.h"
#include "adc.h"
#include <util/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>

ISR(USART_RX_vect){
  char data = Usart::USART_recv();
  Usart::USART_Transmit(data);
}

int main(void){
  int ubrr = Usart::getUBRR(9600);
  Usart::USART_init(ubrr);
  Usart::putString("Hello!\n");

  sei();
  while(1){
  }

  return 0;
}
