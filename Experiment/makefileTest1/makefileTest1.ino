#include <avr/io.h>
#include <util/delay.h>

#define F_CPU = 1600000

int main(void){
  DDRB = 0xff; 

  while(1){
    PORTB ^= _BV(PORTB5);
    _delay_ms(1000);
  }
}

