/*
Giorgio Asganafer 3/6/12

LED infrarossi e potenziale motore alla porta 13
Quando il sensore avverte la vicinanza di qualcosa il motore/segnale 
della porta 13 si abbassa e quando non c'è niente davanti il motore 
riparte.

*/
int inputPIN = A0;               // PIN LED RICEVITORE
int emitterPIN = A1;             // PIN LED EMETTITORE
double minDistanceIntensity = 0; // MASSIMA INTENSITA' RILEVATA
double intensity = 0;            // INTENSITA'
double distance = 0;             // DISTANZA
double reading = 0;              // LETTURA ATTUALE
double ambient = 0;              // LETTURA AMBIENTALE
int readings = 2000;             // COSTANTE NUMERO LETTURE 
int filterValue = 0.1;           // COSTANTE GAIN DEL FILTRO

#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit)) 
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit)) 
// SET PRESCALE PORTE ANALOGICHE

void setup() { 
  pinMode(inputPIN, INPUT); 
  pinMode(emitterPIN, OUTPUT); 
  pinMode(A2, OUTPUT);
 pinMode(13,OUTPUT); 
  Serial.begin(115200); 
  // setta  prescale a 32 
  // riduci la durata della lettura analogica da 128 micros (standard) a 32
  sbi(ADCSRA,ADPS2); 
  cbi(ADCSRA,ADPS1); 
  sbi(ADCSRA,ADPS0); 
} 

void getDistance() { 
  ambient = 0; 
  intensity = 0; 
  digitalWrite(emitterPIN, LOW); // Lettura ambientale 
  for(int i = 0; i < readings; i++) { 
    ambient = ambient + analogRead(inputPIN); 
  } 
  digitalWrite(emitterPIN, HIGH); // Lettura attiva 
  for (int i = 0; i < readings; i++) { 
    intensity = intensity + analogRead(inputPIN); 
  } 
  digitalWrite(emitterPIN, LOW);
  if(ambient < intensity) intensity = intensity - ambient; // Filtro luce ambientale 
    if(intensity > minDistanceIntensity) minDistanceIntensity = intensity; // Salva l'intensità maggiore percepita 
    distance = (distance * filterValue) + (sqrt(minDistanceIntensity / intensity) * (1 - filterValue)); 
} 

void loop() { 
  long time = millis();
  getDistance();
  /*
  Serial.print(1000 / (millis() - time));
  Serial.print(" ");
  Serial.print(distance);
  Serial.print(" ");
  Serial.print(intensity); 
  Serial.print(" ");
  Serial.println(intensity / ambient);
  */
  if(distance<1.10){
    Serial.print("Vicino!\n");
    digitalWrite(13, LOW);
    
  }
  else if(distance>1.10){
    Serial.print(distance);
    Serial.print("\n");
    digitalWrite(13, HIGH);
  }

} 
