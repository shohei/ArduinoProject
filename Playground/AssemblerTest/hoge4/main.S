.NOLIST
.INCLUDE "tn13def.inc" ; Header for ATTINY13 .LIST
.DEF rmp = R16 ; Multipurpose register ;
.DSEG
.ORG 0X0060
.CSEG
.ORG $0000
rjmp Main ; Reset vector reti ; Int vector 1
reti ; Int vector 2
reti ; Int vector 3
reti ; Int vector 4 reti ; Int vector 5 reti ; Int vector 6 reti ; Int vector 7 reti ; Int vector 8 reti ; Int vector 9
Main:
; Init stack
ldi rmp, LOW(RAMEND) ; Init LSB stack
out SPL,rmp
; Init Port B
ldi rmp,(1<<DDB2)|(1<<DDB1)|(1<<DDB0) ; Direction of Port B
out DDRB,rmp
; [Add all other init routines here]
ldi rmp,1<<SE ; enable sleep
out MCUCR,rmp
sei
Loop:
sleep ; go to sleep
nop ; dummy for wake up
rjmp loop ; go back to loop


