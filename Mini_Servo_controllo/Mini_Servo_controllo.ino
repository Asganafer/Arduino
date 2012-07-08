#include <Servo.h>
Servo myservo; //Creo l'oggetto Servo
int angle = 0;	


void setup() {
  myservo.attach(13);
}

void loop() {
  for(angle = 0; angle < 180; angle ++){
    myservo.write(angle); 
    delay(20);
  }
  for(angle = 180; angle >= 1; angle--){
    myservo.write(angle); 
    delay(20);
  }
}
