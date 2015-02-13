int sw[4] = {1,2,3,4};
int stick[4] = {5,6,7,8};

int status_sw[4] = {0,0,0,0};//SW1,SW2,SW3,SW4
int status_stick[4] = {0,0,0,0}; //UP,DOWN,LEFT,RIGHT

void setup(){
for(int i=0;i<4;i++){
  pinMode(sw[i],INPUT_PULLUP);
  pinMode(stick[i],INPUT_PULLUP);
  }
}

void loop(){
  checkJoyStick();
}

void checkJoyStick(){
 for(int i=0;i<4;i++){
   
  if(digitalRead(sw[i])==LOW){
    status_sw[i] = 1;
   }

  if(digitalRead(stick[i]==LOW)){
   status_stick[i] = 1;
  }

  if(digitalRead(sw[i])==HIGH){
    status_sw[i] = 0;
   }

  if(digitalRead(stick[i]==HIGH)){
   status_stick[i] = 0;
  }

 }
}
