// **** INCLUDES *****
#include "LowPower.h"

void setup()
{
    // No setup is required for this library
  Serial.begin(9600);
  Serial.println("start");
}

void loop() 
{
    // Enter power down state for 8 s with ADC and BOD module disabled
    for(int i=0;i<5;i++){
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);      
    char tbs[4];
    sprintf(tbs, "%d",i);
    Serial.println(tbs);
    }
    
    // Do something here
    // Example: Read sensor, data logging, data transmission.
}
