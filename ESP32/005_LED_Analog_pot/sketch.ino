int led = 13;
int pot = 4;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(pot,INPUT);
  Serial.begin(9600);
}

void loop()
{
  int potvalue = analogRead(pot);
  int ledvalue = map(potvalue,0,1023,0,255);
  analogWrite(led,ledvalue);
  Serial.println(ledvalue);
}
