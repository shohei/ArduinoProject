#include <Time.h>
#include <TimeAlarms.h>
#include <LiquidCrystal.h>

#define relayPin 13
int ledPin[5] = {10,9,8,7,6};

timeDayOfWeek_t wdays[5] = {
 dowMonday,
 dowTuesday,
 dowWednesday,
 dowThursday,
 dowFriday,
};

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  delay(1000);
  setTime(20,19,0,1,1,11); // set time to Saturday 8:29:00am Jan 1 2011
  // create the alarms 
//  Alarm.alarmRepeat(8,30,0, MorningAlarm);  // 8:30am every day
//  Alarm.alarmRepeat(17,45,0,EveningAlarm);  // 5:45pm every day 
//  Alarm.alarmRepeat(dowSaturday,8,30,30,WeeklyAlarm);  // 8:30:30 every Saturday 
  for(int i=0;i<5;i++){
    Alarm.alarmRepeat(wdays[i],7,15,0,SilenceHour);  // 7:15am every day 
    Alarm.alarmRepeat(wdays[i],8,0,0,StartLesson);  // 8:00am every day 
    Alarm.alarmRepeat(wdays[i],10,40,0,BreakTime);  // 10:40am every day 
    Alarm.alarmRepeat(wdays[i],11,20,0,BreakOver);  // 11:20am every day 
    Alarm.alarmRepeat(wdays[i],14,30,0,Closing);  // 2:30pm every day 
  }
  pinMode(relayPin,OUTPUT);
  for(int i=0;i<5;i++){
   pinMode(ledPin[i],OUTPUT); 
  }
  
  lcd.print("TTI Silen");
}

void  loop(){  
  digitalClockDisplay();
  Alarm.delay(1000); // wait one second between clock display
}

void triggerRelay(int led){
  digitalWrite(relayPin,HIGH);
  digitalWrite(ledPin[led],HIGH);
  delay(20000); //20 seconds for silen
  digitalWrite(relayPin,LOW);
  digitalWrite(ledPin[led],LOW);
}

void SilenceHour(){
  triggerRelay(0); 
}

void StartLesson(){
  triggerRelay(1);  
}

void BreakTime(){
  triggerRelay(2);  
}

void BreakOver(){
  triggerRelay(3);    
}

void Closing(){
  triggerRelay(4);
}

// functions to be called when an alarm triggers:
void MorningAlarm(){
  Serial.println("Alarm: - turn lights off");    
}

void EveningAlarm(){
  Serial.println("Alarm: - turn lights on");           
}

void WeeklyAlarm(){
  Serial.println("Alarm: - its Monday Morning");      
}

void ExplicitAlarm(){
  Serial.println("Alarm: - this triggers only at the given date and time");       
}

void Repeats(){
  Serial.println("15 second timer");         
}

void OnceOnly(){
  Serial.println("This timer only triggers once");  
}

void digitalClockDisplay()
{
  // digital clock display of the time
  Serial.print(hour());
  lcd.setCursor(0, 1);
  lcd.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println(); 
}

void printDigits(int digits)
{
  Serial.print(":");
  lcd.print(":");
  if(digits < 10){
    Serial.print('0');
    lcd.print('0');
  }
  Serial.print(digits);
  lcd.print(digits);
}

