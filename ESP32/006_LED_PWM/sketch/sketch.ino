
int led = 4;
void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  for(int i=0; i<=255;i++){
    analogWrite(led,i);
    Serial.println(i);
    delay(15);
  }
  for(int i=255; i>=0;i--){
    analogWrite(led,i);
    Serial.println(i);
    delay(15);
  }
}
