//#define F_CPU 1000000UL
#include <avr/io.h>
//#include <util/delay.h>
#include <stdio.h>

void rs_putc (char c)
{
	loop_until_bit_is_set(UCSR0A, UDRE0); 
	UDR0 = c;
}
void rs_puts (char *st)
{
	while (*st) {
		rs_putc (*st);
		if (*(st++) == '\n') rs_putc('\r');
	}
}

int main(void)
{
	UCSR0B = _BV(TXEN0)|_BV(RXEN0); /* TX/RX interrupt enable */
	UCSR0C = 0b00000110;//8bit
	UBRR0H = 0x00;
	UBRR0L = 0x19;
	
	  TCCR1A = 0b10000010;  //10:コンペアマッチAでLOW,10:高速PWM動作
	  TCCR1B = 0b00011001;  //11:高速PWM動作, 001:分周なし
	  ICR1 = 64999; 		  //0から数える. 全体時間 65ms
	  //0.000001 * 65000 : 65ms
	  OCR1A = 0; 		  //0から数える. High時間 32.5ms
	  //0.000001 * 32500 : 32.5ms
	  //OCR1AはPD5ピン	  
	  DDRB |= (1 << PORTB1);
	while(1){
		int i;
		unsigned int val;
		char buf[7];
		unsigned int iter = 15;		
		unsigned long j;
		for(i=0;i<iter;i++){
			j = 0;
			while(j<100000){
  			  val = (64999/iter)*i;
		 	  OCR1A = val;
			  j++;
			};
			//sprintf(buf,"%u\n",val);
			//rs_puts(buf);
		}
		for(i=iter;i>0;i--){
			j = 0;
			while(j<100000){
				val = (64999/iter)*i;
				OCR1A = val;
				j++;
			};
			//sprintf(buf,"%u\n",val);
			//rs_puts(buf);
		}
		//char msg[] = "Hello\n";
		//rs_puts(msg);
		//_delay_ms(2000);
	}
}
