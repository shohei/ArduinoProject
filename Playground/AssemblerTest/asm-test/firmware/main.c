/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include <avr/io.h>

int main(void)
{
    asm volatile(
    ".org        0x0    \t\n"
    "reset:      LDI     R16,LOW(RAMEND)    \t\n"
    "OUT SPL,R16    \t\n"
    "            LDI     R16,0b00001111    \t\n"
    "            OUT     DDRB,R16    \t\n"
    "            ldi     R16,0b00000011    \t\n"
    "            OUT     PORTA,R16    \t\n"
    "LDI R17,10    \t\n"
    "loop:       LDI     R16,0b00001111    \t\n"
    "            OUT     PORTB,R16    \t\n"
    "RCALL wait05    \t\n"
    "            LDI     R16,0b00000000    \t\n"
    "            OUT     PORTB,R16    \t\n"
    "RCALL wait05    \t\n"
    "            DEC     R17    \t\n"
    "            BRNE    loop    \t\n"
    "loop2:      IN      R16,PINA    \t\n"
    "            COM     R16    \t\n"
    "            ANDI    R16,0b00000011    \t\n"
    "            OUT     PORTB,R16    \t\n"
    "            RJMP    loop2    \t\n"
    "wait05:     LDI     R18,5    \t\n"
    "wait052:    RCALL   wait01    \t\n"
    "            DEC     R18    \t\n"
    "BRNE wait052    \t\n"
    "RET    \t\n"
    "wait01:     LDI     R19,100    \t\n"
    "wait012:    RCALL   wait1m    \t\n"
    "            DEC     R19    \t\n"
    "            BRNE    wait012    \t\n"
    "RET    \t\n"
    "wait1m:     LDI     R20,250    \t\n"
    "wait1m2:    NOP    \t\n"
    "            DEC     R20    \t\n"
    "            BRNE    wait1m2    \t\n"
    "RET");

    return 0;   /* never reached */
}
