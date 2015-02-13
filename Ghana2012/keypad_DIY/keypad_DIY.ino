/*
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/

#include <LiquidCrystal.h>
#include <Time.h>
#include <TimeAlarms.h>

//initialize
int silenpin = 0;
int hr;
int mint;
int dy;
int mnth;
int yr;
int keynumber;
int keynumber1;
int keynumber2;
int sensorValue1;
int invalid = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  //Serial.begin(9600);
  lcd.begin(16, 2);
  //lcd.print("Push the number");
  
  setTime(8,29,0,1,1,11); // set time to Saturday 8:29:00am Jan 1 2011  
  //Calendar are included in the library, 
  // so that u don't have to set the day(ex.Saturday) manually, yay!
  //create the alarms 

  //1st class start
  Alarm.alarmRepeat(8,00,0, Silen);  // 8:30am every day
  //1st class end
  Alarm.alarmRepeat(9,30,0, Silen);  // 8:30am every day

  //2nd class start
  Alarm.alarmRepeat(10,00,0, Silen);  // 8:30am every day
  //2nd class end
  Alarm.alarmRepeat(11,30,0, Silen);  // 8:30am every day

  //3rd class start
  Alarm.alarmRepeat(13,00,0, Silen);  // 8:30am every day
  //3rd class end
  Alarm.alarmRepeat(14,30,0, Silen);  // 8:30am every day
 
  //4th class start
  Alarm.alarmRepeat(15,00,0, Silen);  // 8:30am every day
  //4th class end
  Alarm.alarmRepeat(16,30,0, Silen);  // 8:30am every day
  
  //Alarm.alarmRepeat(17,45,0,EveningAlarm);  // 5:45pm every day 
  //Alarm.alarmRepeat(dowSaturday,8,30,30,WeeklyAlarm);  // 8:30:30 every Saturday 
  //Alarm.timerRepeat(15, Repeats);            // timer for every 15 seconds    
  //Alarm.timerOnce(10, OnceOnly);             // called once after 10 seconds 
}

void loop() {  
  digitalClockDisplay();
  Alarm.delay(1000); // wait one second between clock display

  mainMenu();
  //keyboardInput();
}

void digitalClockDisplay()
{
  //lcd.clear();
  lcd.setCursor(0,0);
  // digital clock display of the time
  lcd.print(hour());
  printDigits(minute());
  printDigits(second());
}

void printDigits(int digits)
{
  lcd.print(":");
  if(digits < 10)
    lcd.print('0');
  lcd.print(digits);
}

void Silen(){
  digitalWrite(silenpin,HIGH); 
  //Beep the silen for 10 seconds
  delay(10000);
  digitalWrite(silenpin,LOW);
}

int keyboardInput(){
 //wait for input
 while(1){
   sensorValue1 = analogRead(A0);
     if(sensorValue1 > 0){
         break;
     }
   }

    lcd.setCursor(0,1);   
    switch(sensorValue1){
      
      case 205:
      case 206:
        //Serial.print("1");
        lcd.print("1");
        keynumber1 = 1;
        break;

      case 219:
      case 220:
        //Serial.print("2");
        lcd.print("2");
        keynumber1 = 2;
        break;

      case 235:
      case 236:
        //Serial.print("3"); 
        lcd.print("3"); 
        keynumber1 = 3;
        break;

      case 258:
      case 259:
        //Serial.print("4"); 
        lcd.print("4"); 
        keynumber1 = 4;
        break;

      case 280:
      case 281:
        //Serial.print("5"); 
        lcd.print("5");
        keynumber1 = 5;
        break;

      case 307:
      case 308:
        //Serial.print("6"); 
        lcd.print("6");
        keynumber1 = 6;
        break;

      case 347:
      case 348:
        //Serial.print("7"); 
        lcd.print("7");
        keynumber1 = 7;
        break;

      case 388:
      case 389:
        //Serial.print("8"); 
        lcd.print("8");
        keynumber1 = 8;
        break;

      case 441:
      case 442:
      case 440:
        //Serial.print("9"); 
        lcd.print("9");
        keynumber1 = 9;
        break;

      //CANCEL button
      case 528:
      case 529:
      case 527:
        //Serial.print("*"); 
        //lcd.print("*");
        //homeScreen();
        break;

      case 630:
      case 629:
      case 631:
        //Serial.print("0"); 
        lcd.print("0");
        keynumber1 = 0;
        break;
      
      //Enter and Menu button
      //case 780:
      //case 779:
        //Serial.print("#"); 
        //lcd.print("#");
        //break;
    }  


    while(1){
    //wait for the sensorvalue to become zero
    int sensorValue2 = analogRead(A0); 
    if (sensorValue2 == 0) break;
    }
    //Reading of 1st number finish

   while(1){
   sensorValue1 = analogRead(A0);
     if(sensorValue1 > 0){
         break;
     }
   }
    
    lcd.setCursor(1,1);   
    switch(sensorValue1){      
      
      case 205:
      case 206:
        //Serial.print("1");
        lcd.print("1");
        keynumber2 = 1;
        delay(1000);
        break;

      case 219:
      case 220:
        //Serial.print("2");
        lcd.print("2");
        keynumber2 = 2;
        delay(1000);
        break;

      case 235:
      case 236:
        //Serial.print("3"); 
        lcd.print("3"); 
        keynumber2 = 3;
        delay(1000);
        break;

      case 258:
      case 259:
        //Serial.print("4"); 
        lcd.print("4"); 
        keynumber2 = 4;
        delay(1000);
        break;

      case 280:
      case 281:
        //Serial.print("5"); 
        lcd.print("5");
        keynumber2 = 5;
        delay(1000);
        break;

      case 307:
      case 308:
        //Serial.print("6"); 
        lcd.print("6");
        keynumber2 = 6;
        delay(1000);
        break;

      case 347:
      case 348:
        //Serial.print("7"); 
        lcd.print("7");
        keynumber2 = 7;
        delay(1000);
        break;

      case 388:
      case 389:
        //Serial.print("8"); 
        lcd.print("8");
        keynumber2 = 8;
        delay(1000);
        break;

      case 441:
      case 442:
      case 440:
        //Serial.print("9"); 
        lcd.print("9");
        keynumber2 = 9;
        delay(1000);
        break;

      //CANCEL button
      case 528:
      case 529:
      case 527:
        //Serial.print("*"); 
        //lcd.print("*");
        //homeScreen();
        break;

      case 630:
      case 629:
      case 631:
        //Serial.print("0"); 
        lcd.print("0");
        keynumber2 = 0;
        delay(1000);
        break;
      
      //Enter and Menu button
      case 780:
      case 779:
        //Serial.print("#"); 
        //lcd.print("#");
        keynumber2 = 100;
        break;
    }  

    while(1){
    //wait for the sensorvalue to become zero
    int sensorValue2 = analogRead(A0); 
    if (sensorValue2 == 0) break;
    }
    //Reading of 2nd number finish
  
  if(keynumber2 == 100){
    //Return only 1st number
    keynumber = keynumber1; 
  } else {
    keynumber = keynumber1 * 10 + keynumber2; 
  }
  
  return keynumber;   
 }

void mainMenu(){   
  lcd.setCursor(0, 1);

  int sensorValue1 = analogRead(A0);
    if(sensorValue1 > 0){
      
    switch(sensorValue1){
      //Enter and Menu button
      case 780:
      case 779:
        //Serial.print("#"); 
        lcd.print("Edit the clock");
        delay(2000);
        lcd.clear();
        editClock();
        break;
    }  
   }
}

void editClock(){
  //initialize
  invalid = 0;

  lcd.clear();
  lcd.setCursor(0,0);  
  lcd.print("Year? 0 to 99");
  yr = keyboardInput();
  
  lcd.clear();
  lcd.setCursor(0,0);  
  lcd.print("Month? 1 to 12");
  mnth = keyboardInput();
 if(mnth > 12){
    lcd.setCursor(0,1);
    lcd.print("invalid input"); 
    invalid = 1;
  }  

  lcd.clear();
  lcd.setCursor(0,0);  
  lcd.print("Day? 1 to 31");
  dy = keyboardInput();
  if( dy > 31){
    lcd.setCursor(0,1);
    lcd.print("invalid input"); 
    invalid = 1;
  }  
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hour? 0 to 23");
  hr = keyboardInput();
  if( hr > 23){
    lcd.setCursor(0,1);
    lcd.print("invalid input"); 
    invalid = 1;
  }  

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Minute? 0 to 59");
  //delay(2000);
  //lcd.clear();
  mint = keyboardInput();
  if( mint > 59 ){
    lcd.setCursor(0,1);
    lcd.print("invalid input"); 
    invalid = 1;
  }  

  if(invalid == 0){
    setTime(hr,mint,0,dy,mnth,yr);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Time uploaded!");
    delay(2000);
    lcd.clear();
  } else {
   lcd.clear();
   lcd.setCursor(0,0); 
   lcd.print("Try again");
   delay(2000);
   lcd.clear();
  }
  
}

