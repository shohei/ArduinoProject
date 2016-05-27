int val;
int mval;

int vol;
void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(0);
  mval = map(val,0,1023,0,255);
  analogWrite(9,mval);
  vol = analogRead(5);
  Serial.println(vol);
  delay(100);
}
