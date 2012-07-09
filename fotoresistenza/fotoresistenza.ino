/*
Giorgio Asganafer
24/5/2012

Fotoresistenza con LED che si illumina al passaggio della mano
 */
 
//Variabili della fotoresistenza
int photosensorPin = 0;
int val = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(13, OUTPUT);  
  Serial.begin(9600);    
}

void loop() {
  //assegnazione del valore della fotoresistenza alla variabile "Var"
  val = analogRead(photosensorPin);
  Serial.println(val, DEC);
 
  //controllo della luminosità dell'ambiet 
  if(val>750){
  digitalWrite(13, LOW);   
  }
  else{
  digitalWrite(13, HIGH); 
  }  
  
}
