#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  //uint8_t i;
  //i = 0;
  DDRB = 0xff;
  while (1) {
    PORTB^=(1<<PORTB5);
    _delay_ms(1000);
  }
  return 0;o
}
