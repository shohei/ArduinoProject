#include <AltSoftSerial.h>

AltSoftSerial mySerial;//RX,TX

void setup() {
  mySerial.begin(9600);
  delay(200);
  Serial.begin(9600);
  delay(200);
  Serial.println("serial bypass ready.");
}

void loop() {
  while(mySerial.available()){
//    String s = mySerial.readStringUntil('\n');
//    delay(1);
//    Serial.print(s);
    char c = mySerial.read();
    Serial.write(c);  
  }
}
