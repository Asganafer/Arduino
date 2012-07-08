/*
Giorgio Guidi
24/5/2012

LED e potenziometro
*/

int var;

void setup() {
Serial.begin(9600);
pinMode(13,OUTPUT);
}

//Più si gira il potenziometro e più aumenta il tempo tra un lampeggio e l'altro
void loop() {
var = analogRead(0);
Serial.println(var, DEC); 
digitalWrite(13,HIGH);
delay(var);
digitalWrite(13,LOW);
delay(var);
}
