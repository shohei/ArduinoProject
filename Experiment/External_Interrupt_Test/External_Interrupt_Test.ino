#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT1_vect){
	PORTB = _BV(PORTB5);
        _delay_ms(500);
	PORTB = !_BV(PORTB5);
}
//ISR(INT0_vect){
//        cli();
//        sei();
//}
ISR(PCINT0_vect){
  if(bit_is_set(PINB,PINB0)){
    int i;
    for(i=0;i<3;i++){
      PORTB ^= _BV(PORTB5);
      _delay_ms(500);
    }
  } else if (bit_is_set(PINB,PINB1)){
    int i;
    for(i=0;i<5;i++){
      PORTB ^= _BV(PORTB5);
      _delay_ms(200);
    }
  }
}
void InitINT(void){
	EICRA = 0b00001110;	//INT1-rise,INT0-fall
	EIMSK = 0b00000011;	//INT1,INT2 enable
}
void InitPCINT(void){
        PCICR = 0b00000001; //set PCIE0
        PCMSK0 =0b00000011; //set PB0,PB1 for SW
}
int main(void){
        DDRB = _BV(PORTB5);
  	InitINT();
        InitPCINT();
	sei();	
	for(;;){
	
	}
}
