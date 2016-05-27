#include <MsTimer2.h>

#define WAITTIME 20000
int counter;

void setup() {
  counter=0;
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  delay(1000);
  Serial.println("initialized");
}

void loop() { 
  if(Serial.available()){
    char c = Serial.read();
    if(c=='t'){
      Serial.println("On LED for 20sec.");
      led20sec();
    }
  }
}

void led20sec(){
  ledOn();
  MsTimer2::set(WAITTIME, ledOff); 
  MsTimer2::start();
}

void ledOn(){
 digitalWrite(13,HIGH); 
}

void ledOff(){
  digitalWrite(13,LOW);
  MsTimer2::stop;   
}

