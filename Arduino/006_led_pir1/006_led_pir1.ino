// C++ code
//
//PIR-passive infra red
int red=12;
int green=8;
int pir=2;

void setup()
{
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop(){
 if(digitalRead(pir)==HIGH){
   digitalWrite(red,HIGH);
   digitalWrite(green,LOW);
 }else{
   digitalWrite(red,LOW);
   digitalWrite(green,HIGH);
 }
}