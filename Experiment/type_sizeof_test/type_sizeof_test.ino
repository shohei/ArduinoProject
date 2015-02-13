
void setup(){
  Serial.begin(9600);
  delay(1000);
  Serial.print("char: ");
  Serial.println(sizeof(char));
  Serial.print("unsigned char: ");
  Serial.println(sizeof(unsigned char));
  Serial.print("int: ");
  Serial.println(sizeof(int));
  Serial.print("unsigned int: ");
  Serial.println(sizeof(unsigned int));
  Serial.print("long: ");
  Serial.println(sizeof(long));
  Serial.print("unsigned long: ");
  Serial.println(sizeof(unsigned long));
}

void loop(){
  
}
