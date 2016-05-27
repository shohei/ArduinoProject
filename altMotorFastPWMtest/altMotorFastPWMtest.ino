void setup() {
  TCCR0A = 0b10100011;
  TCCR0B = 0b00000010;
  TCCR2A = 0b10100011;
  TCCR2B = 0b00000010;
 
  
  pinMode(6,OUTPUT);
}

void loop() {
  OCR0A=254;
  _delay_ms(1000);
}
