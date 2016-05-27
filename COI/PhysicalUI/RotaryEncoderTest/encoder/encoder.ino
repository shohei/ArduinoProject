
int dRotAPin  = 2;
int dRotBPin  = 4;
volatile char m_nOldRot = 0;
volatile char m_nValue  = 0;

void setup()  
{
  Serial.begin(9600);
  pinMode(dRotAPin, INPUT);
  pinMode(dRotBPin, INPUT);
  digitalWrite(dRotAPin, HIGH);
  digitalWrite(dRotBPin, HIGH);
  attachInterrupt(0, rotRotEnc, CHANGE);
}

void loop()
{
  Serial.println("m_nValue > ");
  Serial.println(m_nValue, DEC);
  Serial.println(".  ");
}

void rotRotEnc(void)
{
  if(!digitalRead(dRotAPin)){
    if(digitalRead(dRotBPin)){
      m_nOldRot = 'R';
    } else {      
      m_nOldRot = 'L';
    }
  } else { 
    if(digitalRead(dRotBPin)){
      if(m_nOldRot == 'L'){ 
        m_nValue--;
      }
    } else {
      if(m_nOldRot == 'R'){
        m_nValue++;
      }
    }
    m_nOldRot = 0;
  }
}
