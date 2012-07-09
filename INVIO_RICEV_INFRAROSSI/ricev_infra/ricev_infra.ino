/*
Giorgio Asganafer, Davide TheZero 8/7/12

aquisizione di segnali tramite LED infrarossi. Il primo arduino invia
segnali in base al bottone premuto (4 bottoni) e il secondo 
arduino riceve i dati e li utilizza per accendere una lampadina e 
muovere un miniservo
*/

//libreria modificata
#include <PCD8544.h>

#define RITARDO 500

//Dimensione schermo LCD
static const byte LCD_WIDTH = 84;
static const byte LCD_HEIGHT = 48;

static PCD8544 lcd;

int x_t=84, y_t=48;
int infrarosso=A1;
int value[4];

int temp1=0, temp2=300;

//funzione per la rilevazione della luminosità ambientale
void segnale(){
    for(int i=0; i<5; i++){
      temp1=analogRead(A1);
        if(temp1>=temp2 && temp1<(temp2+70)){
          temp2=temp1;
          delay(100);
        }
        lcd.setCursor(0, 2);
        lcd.print("Tmp2= ");
        lcd.setCursor(30, 2);
        lcd.print(temp2);
    }
    
}

void setup() {
  lcd.begin(LCD_WIDTH, LCD_HEIGHT);
  Serial.begin(9600);
  pinMode(infrarosso, INPUT);

  //segnale();
  // The internal 1.1V reference provides for better
  // resolution from the LM35, and is also more stable
  // when powered from either a battery or USB...
  analogReference(INTERNAL);
}


void loop() {
  //Inizializzazione schermo
  static byte xChart = LCD_WIDTH;
  
  //lettura del valore dell'infrarosso
  int sensorValue = analogRead(A1);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(10);// Tempo di stabilizzazione del valore dell'infrarosso
 
  //se il valore è maggiore di quello rilevato inizialmente inizia la memorizzazione del segnale 
  //in un array di 4 elementi
    if(sensorValue>500){
        //ciclo for per la memorizzazione dei degnali
        for(int i=0; i<4; i++){ 
                if(analogRead(A1)>520){  
                  value[i]=1;
                }
                else{
                value[i]=0;
                }
                
        lcd.setCursor(0, 0);
        lcd.print("Code= ");
        lcd.setCursor(30, 0);
        lcd.print(value[0]);
        lcd.setCursor(37, 0);
        lcd.print(value[1]);
        lcd.setCursor(44, 0);
        lcd.println(value[2]);
        lcd.setCursor(51, 0);
        lcd.print(value[3]);
        delay(RITARDO); 
        }
        
    }else{
        
        }
  //scrittura sullo schermo del valore della luminosità rilevata
  lcd.setCursor(0, 5);
  lcd.print("value=");
  lcd.println(sensorValue);
  
  /*
  if(value[0]==1 && value[1]==0 && value[2]==0 && value[3]==0){
   
  }
  else if(value[0]==1 && value[1]==0 && value[2]==1 && value[3]==1){
  
  }*/
  segnale();
}