/*
Giorgio Guidi
25/5/12

3 LED si accednono ad intermittenza quando il bottone viene premuto
*/
int  val = 0;                 
  
void setup() {  
  pinMode(13, OUTPUT);    //LED 1
  pinMode(13, OUTPUT);    //LED 2
  pinMode(13, OUTPUT);    //LED 3
  pinMode(7, INPUT);      //BOTTONE 1
}  
  
void loop() {  
  //se il pulsante viene premuto viene rchiamata la funzione
  val = digitalRead(7); 
  if (val == HIGH) {  
    bottoni();
  }  
}

void bottoni(){
  for(int i=0; i<3; i++){
    digitalWrite(13,HIGH);
    delay(500);
    //digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
    delay(500);
    //digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
    delay(500);
    //digitalWrite(11,LOW);
  }
}
