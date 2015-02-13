/*
  Serial Event example
 
 When new serial data arrives, this sketch adds it to a String.
 When a newline is received, the loop prints the string and 
 clears it.
 
 A good test for this is to try it with a GPS receiver 
 that sends out NMEA 0183 sentences. 
 
 Created 9 May 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/SerialEvent
 
 */

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  //Serial.begin(9600);
  Serial.begin(19200);
  delay(2000);
  // reserve 200 bytes for the inputString:
  //inputString.reserve(200);  
}

void test(){
  Serial.print("GET / HTTP/1.1 \r\n");
  Serial.print("Host: http://133.242.160.150\r\n");
  Serial.print("User-Agent: SmartCitizen\r\n");
}

void loop() {
  Serial.print("PUT /add HTTP/1.1\r\n");
  Serial.print("Host: http://data.smartcitizen.me\r\n");
  Serial.print("User-Agent: SmartCitizen\r\n");
  Serial.print("X-SmartCitizenMacADDR:");
  Serial.print("00:00:00:00:00:00\r\n");
  Serial.print("X-SmartCitizenApiKey:"); 
  Serial.print("f5f2b1ccbdf1eb4e0542d70b3459076a83a0e9d2\r\n");
  Serial.print("X-SmartCitizenVersion: 1.1-0.8.5-A\r\n");
  Serial.print("X-SmartCitizenData: [ {");
  Serial.print("\"temp\": \"24700\"");
  Serial.print(",\"hum\": \"32800\"");
  Serial.print(",\"light\":\"220\"");
  Serial.print(",\"bat\": \"200\"");
  Serial.print(",\"panel\": \"1000\"");
  Serial.print(",\"co\": \"3240\"");
  Serial.print(", \"no2\": \"4850\""); 
  Serial.print(",\"noise\": \"100\""); 
  Serial.print(", \"nets\": \"1\"");
  Serial.print(",\"timestamp\":");
  Serial.print("\"2014-02-27 09:20:09 UTC\"");
  Serial.print("} ]\r\n\r\n");  

  while(1);
  // print the string when a newline arrives:
//  if (stringComplete) {
//    Serial.println(inputString); 
//    // clear the string:
//    inputString = "";
//    stringComplete = false;
//  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}


