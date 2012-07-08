/*
Giorgio Guidi
24/5/2012

LED e potenziometro
*/

int temp;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
}

//Più si gira il potenziometro e più aumenta 
//il tempo tra un led e un altro
void loop() {
  temp = analogRead(0);
  Serial.println(temp, DEC);
   //lampeggio led 
  digitalWrite(13,HIGH);
  delay(temp);
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  delay(temp);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  delay(temp);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
  delay(temp);
  digitalWrite(10,LOW);
  digitalWrite(9,HIGH);
  delay(temp);
  digitalWrite(9,LOW);
}
