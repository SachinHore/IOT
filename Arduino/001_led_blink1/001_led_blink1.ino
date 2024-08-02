// C++ code
//
int RED = 13;
int GREEN =11;
int YELLOW =12;
void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
}

void loop()
{
  digitalWrite(RED, HIGH);
  delay(2000); // Wait for 1000 millisecond(s)
  digitalWrite(RED, LOW);
  
  digitalWrite(YELLOW, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(YELLOW, LOW);
  
  digitalWrite(GREEN, HIGH);
  delay(5000); // Wait for 1000 millisecond(s)
  digitalWrite(GREEN, LOW);
  
}