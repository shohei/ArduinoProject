unsigned long time;

void setup() {
  // put your setup code here, to run once:
  Serial3.begin(115200);
  delay(1000);
  Serial3.println("Serial 3 is now go.");
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  time = millis();
  delay(50);
  Serial3.println(time);
//  Serial3.println("hoge moge");  
//  delay(1000);
}
