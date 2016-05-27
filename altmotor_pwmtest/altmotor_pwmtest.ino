int ahigh=2;
int asd=3;
int bhigh=4;
int bsd = 5;
int chigh = 6;//pwm
int csd = 7;  
void setup() {
  // put your setup code here, to run once:
  pinMode(ahigh,OUTPUT);
  pinMode(asd,OUTPUT);
  pinMode(bhigh,OUTPUT);
  pinMode(bsd,OUTPUT);
  pinMode(chigh,OUTPUT);
  pinMode(csd,OUTPUT);  
  
  digitalWrite(asd,LOW);
  digitalWrite(bsd,HIGH);
  digitalWrite(csd,HIGH);//shutdown c

//  digitalWrite(ahigh,HIGH);
  digitalWrite(bhigh,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(chigh,254);

}
