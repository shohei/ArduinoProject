void setup(){
  pinMode(8,OUTPUT);
}
void loop(){
  for(int i=0;i<10;i++){
    analogWrite(8,255/10*i);
  }
  for(int i=10;i>0;i--){
    analogWrite(8,255/10*i);
  }
}
