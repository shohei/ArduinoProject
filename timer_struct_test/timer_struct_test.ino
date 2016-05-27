int global_cnt;

enum LED {
  LED1,
  LED2,
  LED3
};

typedef struct timer {
  enum LED led;
  unsigned long starttime;  
  unsigned int interval;
};

struct timer* timers[10];

void setup() {
  global_cnt=0;
}

void loop() {
  for(int i=0;i<global_cnt;i++){
      checkTimer(i);
    }
  
  if(Serial.available()){
    char c = Serial.read();
    if(c=='t'){
      register_timer(timers[global_cnt],LED1,20000);
      global_cnt++;
    }
  }
}

void register_delay(timer* t, enum LED led, int interval){
      t->led = LED1;
      t->starttime = millis();
      t->interval;
      Serial.println("LED: "+t->led);
      Serial.println("TIME: "+t->starttime);
}

void checkTimer(){
    unsigned long stime = timers[i]->starttime;
    int interval = timers[i]->interval;
    if((millis() - stime) > interval){
      //break and unregister timer;
      //global_cnt--;??       
    }
}

