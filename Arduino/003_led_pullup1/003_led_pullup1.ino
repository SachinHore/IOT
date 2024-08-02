void setup()
{
  pinMode(13, OUTPUT);
  pinMode(4, INPUT);
}

void loop()
{
  int input = digitalRead(4);
  if(input == 1){
    digitalWrite(13, HIGH);
  }else{
    digitalWrite(13, LOW);
  }
}