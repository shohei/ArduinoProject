#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define FOSC 16000000UL
#define BAUD 9600
#define MYUBRR ((FOSC/(16UL*BAUD))-1)

void USART_init(unsigned int ubrr){
  UBRR0H = (ubrr>>8);
  UBRR0L = ubrr;
  UCSR0B = _BV(RXEN0)|_BV(TXEN0); //RX-TX enable
  UCSR0C = (3<<UCSZ00);//define data frame: CSZ = CharacterSiZe
}

void USART_Transmit(unsigned char data){
  loop_until_bit_is_set(UCSR0A,UDRE0);
  UDR0 = data;
}

char USART_recv(void)
{
  while(!(UCSR0A & (1<<RXC0)));
  return UDR0;
}

void putString(char msg[])
{
  int i;
  for(i=0;msg[i];i++){
    USART_Transmit(msg[i]);
  }
}

void PB1_PWM_init(){
  DDRB |= _BV(PORTB1);//For PWM output
  TCCR1A = _BV(COM1A1)|_BV(WGM11); //Compare match A enable,Fast PWM (ICR1 as TOP)
  TCCR1B = _BV(WGM13)|_BV(WGM12)|_BV(CS10); //Fast PWM (ICR1 as TOP),Clock Source enable
  ICR1 = 65000;
}

void PB1_dim(){
  int i;
  char buf[20];
  for(i=0;i<10;i++){
    unsigned long j;
    for(j=0;j<1000000;j++){
        //nop;
    }
  OCR1A = 6500 * i;
  //_delay_ms(200);
  }
}

void PWM_test(){
  ICR1 = 65000;
  int i;
  for(i=0;i<10;i++){
  OCR1A = 6500*i;
  _delay_ms(200);
  }
  for(i=10;i>0;i--){
  OCR1A = 6500*i;
  _delay_ms(200);
  }
}

int main(void){
  DDRB |= _BV(PORTB5);//For monitor LED13
  USART_init(MYUBRR); 

  char data;
  putString("Hello\n");
  putString("Hello\n");

  PB1_PWM_init();
  OCR1A = 65000;
  while(1){
      //data = USART_recv();
      //USART_Transmit(data);
      //PB1_dim();
      PWM_test();
  }
  return 0;  
}


