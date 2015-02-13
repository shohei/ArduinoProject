#include <SPI.h>
#include <LiquidCrystal.h>
#include <avr/interrupt.h>
 
int col = 0;
LiquidCrystal lcd(2, 3, 4, A0, A1, A2, A3);
char lcdf = 0;
String strSPI = "";
boolean strSPIcomplete = false;
int charcnt = 0; 
 
// -----------------------------------------------------------------------------
// --- Interrupt Service Routine (SPI transfer complete)
// -----------------------------------------------------------------------------
ISR(SPI_STC_vect) {
  char ch;
 
  ch = SPDR;
  charcnt++;
  strSPI += ch;
  if(ch == '\r') {
    strSPIcomplete = true;
  }
}
 
// -----------------------------------------------------------------------------
// --- Setup
// -----------------------------------------------------------------------------
void setup() {
   
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
 
  // initialize SPI
  pinMode(SS, INPUT);
  pinMode(SCK, INPUT);
  pinMode(MOSI, INPUT);  
  pinMode(MISO, OUTPUT);  
  // SPI slave mode
  SPCR &= ~(1<<MSTR);
  // SPI MSB first = 0, LSB First = 1
  SPCR &= ~(1<<DORD);
  // SPCR |= (1<<DORD);
  // SPI transfer mode
  // mode 0 = CPOL:0 CPHA:0   
  SPCR &= ~(1<<CPOL);
  SPCR &= ~(1<<CPHA);
  // SPI enable
  SPCR |= (1<<SPE);
  // SPI interrupt enable
  SPCR |= (1<<SPIE);  
 
   Serial.begin(9600);
  lcd.begin(16,2);
  //lcd.print("abc");
}
 
// -----------------------------------------------------------------------------
// --- main loop
// -----------------------------------------------------------------------------
void loop() {
 
  if(strSPIcomplete == true) {
    lcd.clear();
    if(lcdf == 0) {
      lcd.setCursor(0,0);
      lcdf = 1;
    } else {
      lcd.setCursor(0,1);
      lcdf = 0;
    }
    lcd.print(strSPI);
    lcd.print(" ");
    lcd.print(charcnt);
    Serial.print(strSPI);
    Serial.print(" ");
    Serial.println(charcnt);
    charcnt = 0;
    strSPI = "";
    strSPIcomplete = false;
  }
}
