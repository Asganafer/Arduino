/*
Giorgio "Asganafer" Guidi
23/5/12

Semaforo a 3 LED
 */

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(13, OUTPUT);    //led verde
  pinMode(12, OUTPUT);    //led giallo
  pinMode(11, OUTPUT);    //led rosso
  
  pinMode(10,OUTPUT);  //led di controllo
}

int conta=0;

void loop() {
  conta++;
  digitalWrite(13, HIGH);  
  delay(3000);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
  digitalWrite(11,HIGH);
  delay(3000);
  digitalWrite(11,LOW);
  
  //arrivato a 3 si illumina il LED
  if(conta==3){
    digitalWrite(10, HIGH);
  }
}
