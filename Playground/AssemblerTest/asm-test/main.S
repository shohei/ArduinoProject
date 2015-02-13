.org 0x0
reset:      LDI     R16,LOW(RAMEND);
OUT SPL,R16;
            LDI     R16,0b00001111;
            OUT     DDRB,R16;
            ldi     R16,0b00000011;
            OUT     PORTA,R16;
LDI R17,10;
loop:       LDI     R16,0b00001111;
            OUT     PORTB,R16;
            RCALL wait05;
            LDI     R16,0b00000000;
            OUT     PORTB,R16;
            RCALL wait05;
            DEC     R17;
            BRNE    loop;
loop2:      IN      R16,PINA;
            COM     R16;
            ANDI    R16,0b00000011;
            OUT     PORTB,R16;
            RJMP    loop2;
wait05:     LDI     R18,5
wait052:    RCALL   wait01
            DEC     R18;
            BRNE wait052;
            RET;
wait01:     LDI     R19,100
wait012:    RCALL   wait1m;
            DEC     R19;
            BRNE    wait012;
            RET;
wait1m:     LDI     R20,250;
wait1m2:    NOP;
            DEC     R20;
            BRNE    wait1m2;
            RET;
