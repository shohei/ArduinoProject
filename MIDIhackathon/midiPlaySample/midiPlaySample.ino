#include <EEPROM.h>
#include "sounddata.h"
#include <MIDI.h>

// the current address in the EEPROM (i.e. which byte
// we're going to write to next)
byte value;
prog_uint16_t data;
prog_uint16_t data1;
prog_uint16_t data2;
prog_uint16_t data3;


void setup()
{
  //MIDI.begin(1);            	// Launch MIDI with default options
    
  Serial.begin(31250);
  Serial.begin(9600);
    while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  //Serial.print((sizeof charSet)/(sizeof charSet[0]));
  for(int i=0;i < (sizeof charSet)/(sizeof charSet[0]);i++){
    data = pgm_read_word_near(&charSet[i]);
    if(data > 0x7F){
      Serial.print(data);
      Serial.println();
      delay(1000);
      }     
   }
     // Serial.write(data);
    //for(int k=0;k<((sizeof charSet)/(sizeof charSet[0]))/3;k++){
    //  data1 = pgm_read_word_near(&charSet[3*k]);
    //  data2 = pgm_read_word_near(&charSet[3*k+1]);
    //  data3 = pgm_read_word_near(&charSet[3*k+2]);
    //  MIDI.sendNoteOn(data1,data2,1);  // Send a Note (pitch 42, velo 127 on channel 1)
    //}
//
//    Serial.print("writing ");
//    Serial.print(data,HEX);
//    Serial.print("into address");
//    Serial.print(i);
//    Serial.println();
//    EEPROM.write(i, data);
  //}
}

void loop()
{
     for(int i=0;i <(sizeof charSet)/(sizeof charSet[0]);i++){
     value = EEPROM.read(i);
     Serial.print("ADDRESS-");
     Serial.print(i);
     Serial.print(", DATA:");
     Serial.print(value, HEX);    
     Serial.println();
    }

}
