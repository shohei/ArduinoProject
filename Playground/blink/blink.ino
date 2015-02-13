#include <avr/io.h>
#include <util/delay.h>

int main(void){
  DDRB = 0xff;
  while(1){
    PORTB ^= _BV(PORTB5);
    _delay_ms(1000);
  }
}

