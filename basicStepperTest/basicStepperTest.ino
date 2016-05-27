// DRV8825 stepper5(200, 66, 67);//Z
int enablePin = 44;
int directionPin = 66;
int stepPin = 67;
int j;
void setup() { 
	Serial.begin(9600);
	Serial.println("Starting StepperTest");

	pinMode(directionPin, OUTPUT);
	pinMode(stepPin, OUTPUT);
	pinMode(enablePin,OUTPUT);
  //digitalWrite(directionPin, LOW);
}

void loop() 
{
	Serial.println("START");
	for(j=0; j<=199; j++) {
		digitalWrite(directionPin, HIGH);  
	    digitalWrite(enablePin,LOW);
		digitalWrite(stepPin, HIGH);
		delay(20);
		digitalWrite(stepPin, LOW);
		delay(25);
	    digitalWrite(enablePin,HIGH);
	}
	Serial.println("CHANGE DIRECTION");
	delay(5000);

	for(j=0; j<=199; j++) {
		digitalWrite(directionPin, LOW);
	    digitalWrite(enablePin,LOW);
		Serial.println("STEP");  
		digitalWrite(stepPin, HIGH);
		delay(20);
		digitalWrite(stepPin, LOW);
		delay(25);
	    digitalWrite(enablePin,HIGH);
	}
	Serial.println("END");
}
