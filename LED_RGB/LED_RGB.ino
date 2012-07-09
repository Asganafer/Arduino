/*
  Giorgio Asganafer
  6/6/12
  
  LED RGB controllato da 3 bottoni
 */
const int R = 13;
const int G = 12;
const int B = 11;


void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
}

int count=0, buttonState=0;

void loop() {
buttonState = digitalRead(7);
if (digitalRead(7) == HIGH) {    
    digitalWrite(R, 0);  
    digitalWrite(G, 255);  
   digitalWrite(B, 255);
  }
 if (digitalRead(6) == HIGH) {    
    digitalWrite(R, 255);  
    digitalWrite(G, 0);  
   digitalWrite(B, 255);
 }
 if (digitalRead(5) == HIGH) {    
    digitalWrite(R, 255);  
    digitalWrite(G, 255);  
   digitalWrite(B, 0);
  }
 else{
 digitalWrite(R, 255);  
 digitalWrite(G, 255);  
 digitalWrite(B, 255);  
 } 
}
