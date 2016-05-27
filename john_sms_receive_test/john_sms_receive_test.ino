#include <SoftwareSerial.h>

#define LED1 2
#define LED2 3
#define LED3 4

SoftwareSerial mySerial(7, 8);

void initGSM(){
 mySerial.print("ATE0\r");
 mySerial.print("AT\r");
 mySerial.print("AT+CMGF=1\r");
 mySerial.print("AT+CNMI=1,2,0,0,0\r");
}

void setup() {
  mySerial.begin(19200);               // the GPRS baud rate
  Serial.begin(19200);    // the GPRS baud rate
  delay(2000);
  //initialize GMS for receiving
  initGSM();
}

void loop() {  
  String response;
  bool begin = false;
  bool end = false;

  while (!end) {
    if (mySerial.available() > 0)
    {
      begin = true;
      response = mySerial.readStringUntil('\n');
      Serial.println("response: "+response);
      end = true;
    }
  }
     
     if(response.startsWith("1")){
       clearLeds();  
       turnOnLed1();     
     } else if(response.startsWith("2")){
       clearLeds();  
       turnOnLed2();           
     } else if(response.startsWith("3")){
       clearLeds();  
       turnOnLed3();     
     }                      
}

void ShowSerialData()
{
  while(mySerial.available()!=0)
    Serial.write(mySerial.read());
}

void turnOnLed1(){
  digitalWrite(LED1,HIGH);
  Serial.println("TURN ON LED1");
}

void turnOnLed2(){
  digitalWrite(LED2,HIGH);  
  Serial.println("TURN ON LED2");
}

void turnOnLed3(){
  digitalWrite(LED3,HIGH);
  Serial.println("TURN ON LED3");
}


void clearLeds(){
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);  
}

