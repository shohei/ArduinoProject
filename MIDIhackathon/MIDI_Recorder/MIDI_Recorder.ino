#include "sounddata.h"
#include <EEPROM.h>
int recPin = 3;
int dumpPin = 4;
unsigned char data1;
unsigned char data2;
unsigned char data3;
unsigned char data4;
int i = 0;
byte value;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete


void setup() {
  Serial.begin(31250);
  //while(!Serial.available()){
   // 
  //}
  pinMode(recPin,INPUT);
  pinMode(dumpPin,INPUT);
  inputString.reserve(200);
}

//velocity is 0x45 or 0x00
void loop() {
  //noteOn(0x90, note, velocity,duration);
   if (stringComplete) {
    Serial.println(inputString); 
    inputString = "";
    stringComplete = false;
    }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read(); 
    Serial.println(inChar);
    inputString += inChar;    
    if (inChar == 0x55) {
    //if((sizeof inputString)/(sizeof inputString[0])>200){
      stringComplete = true; 
    } 
  }
}

void noteOn(int cmd, int pitch, int velocity, int duration) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
  delay(duration);
}

void dumpCode(){
    if(digitalRead(dumpPin)==HIGH){
    for(int k=0;k<i*4;k++){
     value = EEPROM.read(k);
     Serial.print(value,HEX);
     }
     i = 0;
  } 
}

void recCode(){
    if(digitalRead(recPin)==HIGH){    
//    data = Serial.read()
//    data2 = 
//    data3 = 
//    data4 = 
    EEPROM.write(4*i, data1);
    EEPROM.write(4*i+1, data2);
    EEPROM.write(4*i+2, data3);
    EEPROM.write(4*i+3, data4);
    i += 1;  
  }
}
