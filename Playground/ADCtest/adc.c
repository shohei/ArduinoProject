#include <avr/io.h>
#include <util/delay.h>

#define F_OSC 16000000UL
#define BAUD 9600
#define MYUBRR ((F_OSC/(BAUD*16UL))-1)
#define sbi(BYTE,BIT) BYTE|=_BV(BIT) 
#define cbi(BYTE,BIT) BYTE&=~_BV(BIT) 

void usart_init(unsigned int ubrr){
  UBRR0H = (ubrr>>8);
  UBRR0L = ubrr;
  UCSR0B = _BV(RXEN0)|_BV(TXEN0);
  UCSR0C = (3<<UCSZ00);
}

void usart_send(unsigned char data){
  while(!(UCSR0A&_BV(UDRE0)));
  UDR0 = data;
}

void putString(char strings[]){
  int i;
  for(i=0;strings[i];i++){
      usart_send(strings[i]);
  }
}

void adc_init(){
  ADMUX |= _BV(REFS0);//selecting ADC0=PC0
  ADCSRA |= _BV(ADEN)|_BV(ADSC);//ADC enable, Start conversation;
}

int adc_conv(int pin){
  int res;  
  ADMUX = _BV(REFS0)|pin;
  cbi(ADCSRA,ADIF);
  sbi(ADCSRA,ADSC);
  loop_until_bit_is_set(ADCSRA,ADIF);
  res = ADCL; 
  res += (ADCH<<8); 
  return res;
}

int main(void){
  usart_init(MYUBRR);

  int data; 
  char buf[10];
  adc_init();
  while(1){
      data = adc_conv(0);
      itoa(data,buf,10);
      putString(buf);
      putString("\n");
      _delay_ms(500);
  }
  return 0;
}

