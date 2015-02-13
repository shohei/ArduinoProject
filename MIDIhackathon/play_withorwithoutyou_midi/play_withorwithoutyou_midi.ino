void setup() {
  //  Set MIDI baud rate:
  Serial.begin(31250);
}

int time = 150;
void loop() {
  // play notes from F#-0 (0x1E) to F#-5 (0x5A):
  //  for (int note = 0x1E; note < 0x5A; note ++) {
  //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
  for(int i=0;i<4;i++){ 
    int note;
    switch(i){
    case 0: 
      note = 0x3C;  
      break;
    case 1:
      note = 0x37;
      break;
    case 2:
      note = 0x39;
      break;
    case 3:
      note = 0x35;
      break;
    }
    for(int k=0;k<8;k++){
      noteOn(0x90, note, 0x45);
      delay(time);
      //Note on channel 1 (0x90), some note value (note), silent velocity (0x00):
      noteOn(0x90, note, 0x00);   
      delay(time);
    }
  }
}
//  }

//  plays a MIDI note.  Doesn't check to see that
//  cmd is greater than 127, or that data values are  less than 127:
void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

