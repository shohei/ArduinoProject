#include <avr/io.h> 

.global main 
main:    
        out     PORTB, r16               ;Error, wrong address space
        out     _SFR_IO_ADDR(PORTB), r16 ;Ok 
        sts     PORTB, r16               ;Ok 

#define __SFR_OFFSET 0 
        out     PORTB, r16               ;Ok 
        out     _SFR_IO_ADDR(PORTB), r16 ;Ok 
        sts     PORTB, r16               ;Error, wrong address space

loop:   rjmp loop 
