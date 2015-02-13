#define INA 53
#define INB 51
#define PWM2 13
#define POT 0

int errorcw = 0;
int errorccw = 0;
int correction = 0;
double kp = 57;
double ki = 26;
double kd = 12;
int PID = 0;
int error = 0;
int last_error = 0;
int angle = 0;
int sp = 839;

void setup()
{
    Serial.begin(9600);
    pinMode(INA, OUTPUT);
    pinMode(INB, OUTPUT);
    pinMode(PWM2, OUTPUT);
    pinMode(POT, INPUT);

}

void loop()
{
    char buffer[5];
    angle = analogRead(POT);
    Serial.print("#S|PIDLOG|[");
    Serial.print(itoa((angle), buffer, 10));
    Serial.println("]#");
    if(angle < sp)
    {
        errorcw = (sp-angle);
        correction = calcPid(errorcw);
        analogWrite(PWM2, correction);
        digitalWrite(INA, LOW);
        digitalWrite(INB, HIGH);
    }
    if(angle > sp)
    {
        errorccw = (angle-sp);
        correction = calcPid(errorccw);

        analogWrite(PWM2, correction);
        digitalWrite(INA, HIGH);
        digitalWrite(INB, LOW);
    }
    //  delay(50);
    return;
}

int calcPid(int error)
{
    PID = (kp*(error))+(ki*(error+last_error))+(kd*(error-last_error));
    last_error = error;

    return constrain(PID, 0, 255);
}
