#include <avr/io.h>
#include <util/delay.h>

int main(void){
  DDRB |= _BV(PORTB5);
  while(1){
    PORTB ^= _BV(PORTB5);
    _delay_ms(1000);
  }

}
