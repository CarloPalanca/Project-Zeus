// RIGHT DRIVER
#define RPWM2 11
#define LPWM2 10
#define REN2  9
#define LEN2  8
//LEFT DRIVER
#define RPWM1 6
#define LPWM1 5
#define REN1  4
#define LEN1  3

#define moveSpeed  255
#define actDelay   10

void setup()
{
  pinMode(LPWM1, OUTPUT);  pinMode(RPWM1, OUTPUT);
  pinMode(LPWM2, OUTPUT);  pinMode(RPWM2, OUTPUT);
  pinMode(LEN1, OUTPUT);   pinMode(REN1, OUTPUT);
  pinMode(LEN2, OUTPUT);   pinMode(REN2, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

void loop()
{
  int AINL = digitalRead(A2);
  int AINC = digitalRead(A1);
  int AINR = digitalRead(A0);

  if (!AINL && AINC && !AINR) //010
  {
    digitalWrite(LEN1, HIGH);
    digitalWrite(LEN2, HIGH);
    digitalWrite(REN1, HIGH);
    digitalWrite(REN2, HIGH);
    analogWrite(LPWM1, 0);  
    analogWrite(LPWM2, moveSpeed);    
    analogWrite(RPWM1, moveSpeed);  
    analogWrite(RPWM2, 0);    
    delay(actDelay);
  }
  else if (AINL && !AINC && !AINR) //100
  {
    digitalWrite(LEN1, HIGH);
    digitalWrite(LEN2, HIGH);
    digitalWrite(REN1, HIGH);
    digitalWrite(REN2, HIGH);
    analogWrite(LPWM1, moveSpeed);  
    analogWrite(LPWM2, moveSpeed);  
    analogWrite(RPWM1, moveSpeed);  
    analogWrite(RPWM2, 0);    
    delay(actDelay);
  }
  else if (!AINL && !AINC && AINR) //001
  {

    digitalWrite(LEN1, HIGH);
    digitalWrite(LEN2, HIGH);
    digitalWrite(REN1, HIGH);
    digitalWrite(REN2, HIGH);
    analogWrite(LPWM1, 0);  
    analogWrite(LPWM2, moveSpeed);    
    analogWrite(RPWM1, moveSpeed);  
    analogWrite(RPWM2, moveSpeed);  
    delay(actDelay);
  }
  else if (AINL && AINC && AINR) //111
  {

    digitalWrite(LEN1, HIGH);
    digitalWrite(LEN2, HIGH);
    digitalWrite(REN1, HIGH);
    digitalWrite(REN2, HIGH);
    analogWrite(LPWM1, moveSpeed);  
    analogWrite(LPWM2, moveSpeed);  
    analogWrite(RPWM1, moveSpeed);  
    analogWrite(RPWM2, moveSpeed);  
    delay(actDelay);
  }
}
