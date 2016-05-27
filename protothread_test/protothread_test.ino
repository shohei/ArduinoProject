#include <pt.h> 
#define LEDPIN 13  

static struct pt pt1;

static int protothread1(struct pt *pt, int interval) {
  static unsigned long timestamp = millis();
  Serial.println("LED ON");
  digitalWrite(13,HIGH);
  PT_BEGIN(pt);
  while(1){
    PT_WAIT_UNTIL(pt, millis() - timestamp > interval );      
    Serial.println("wait halt");
  }
  PT_END(pt);
  digitalWrite(13,LOW);
  Serial.println("LED OFF");
}

void setup() {
  pinMode(LEDPIN, OUTPUT); 
  Serial.begin(9600);
  delay(1000);
  Serial.println("initialized");
  PT_INIT(&pt1); 
}

void loop() {
  if(Serial.available()){
    char c = Serial.read();
    if(c=='t'){
      protothread1(&pt1, 1000);  
    }
  }
}
