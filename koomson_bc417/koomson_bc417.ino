byte rx = 0;
byte tx = 1;
byte ledPin = 13;
int incomingString;
byte i = 1;

void setup() 
{
  Serial.begin( 9600 );
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);
  pinMode(ledPin,OUTPUT);
}

void loop()
{
    Serial.println("AT");
    incomingString = Serial.read();
    switch (incomingString)
    {
    case 'OK':
      digitalWrite(ledPin, HIGH);
      delay( 1500 );
      break;
    default:
      for (i=1; i<10; i++)
      {
        digitalWrite(ledPin, HIGH);
        delay( 250 );
        digitalWrite(ledPin, LOW);
        delay( 250 );
      }
    }
    delay( 1000 );
    digitalWrite(ledPin, LOW);
    delay( 2000 );
}
