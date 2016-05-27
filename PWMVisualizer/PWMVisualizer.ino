void setup(){
  pinMode(9,OUTPUT);  
  Serial.begin(9600);
}

void loop(){  
  int val;
  int i;
  float wvolt;
  float rvolt;
  for(i=0;i<255;i=i+20){
    analogWrite(9,i); 
    val = analogRead(A0);
//    Serial.print("output PWM: ");
    wvolt = i/255.0;
//    Serial.print(wvolt);
//    Serial.print("[V] , read Voltage: ");
    rvolt = val / 1023.0;    
    Serial.println(rvolt);    
    //Serial.println("[V]");
    delay(100);  
  }
}

