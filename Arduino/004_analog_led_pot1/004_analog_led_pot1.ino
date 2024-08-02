// C++ code
//
void setup()
{
  pinMode(9, OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop()
{
  int potvalue = analogRead(A0);
  int ledvalue = map(potvalue,0,1023,0,255);
  analogWrite(9,ledvalue);
  Serial.println(ledvalue);
}