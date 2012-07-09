Giorgio Asganafer 

#include <Servo.h>
Servo myservo; //Creazione dell'oggetto servo
int angle = 0;	


void setup() {
  myservo.attach(13);
}

//giro di 180°
void loop() {
  for(angle = 0; angle < 180; angle ++){
    myservo.write(angle); 
    delay(20);
  }

//altro giro per tornare alla posizione iniziale
  for(angle = 180; angle >= 1; angle--){
    myservo.write(angle); 
    delay(20);
  }
}
