/*
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 7
 * LCD D5 pin to digital pin 6
 * LCD D6 pin to digital pin 5
 * LCD D7 pin to digital pin 4
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/


#include <LiquidCrystal.h>

#define sw1 2
#define sw2 3

unsigned long int_time,guard_time;

volatile int current = 0;
volatile int in = 0;
volatile int out = 0;

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup(){
 pinMode(sw1,INPUT);  
 pinMode(sw2,INPUT);
 attachInterrupt(0,countUp,RISING);//PIN2 for UNO
 attachInterrupt(1,countDown,RISING);//PIN3 for UNO
 Serial.begin(9600);
 lcd.begin(16,2);
 delay(1000);
 lcdDisp();
}

void loop(){
 
}

void countUp(){
  if( millis() > guard_time ) 
  {
    int_time = millis();
    guard_time = int_time + 500UL;
    current++;
    in++;
    Serial.print(current);
    Serial.print(" people is inside. ");
    Serial.print(in);
    Serial.println(" people coming in today.");
    lcdDisp();
  }
}

void countDown(){
  if( millis() > guard_time ) 
  {
    int_time = millis();
    guard_time = int_time + 500UL;
    current--;
    out++;
    Serial.print(out);
    Serial.print(" people going out. Still ");
    Serial.print(current);
    Serial.println(" people is inside.");
    lcdDisp();  
  }
}

void lcdDisp(){
    lcd.setCursor(0, 0);
    lcd.print("CURRENT: ");
    lcd.print(current);
    lcd.setCursor(0, 1);
    lcd.print("IN: ");
    lcd.print(in);
    lcd.print(" OUT: ");
    lcd.print(out);
 }
