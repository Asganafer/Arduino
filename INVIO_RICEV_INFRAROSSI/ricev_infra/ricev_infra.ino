/*
Giorgio Asganafer Guidi, Davide TheZero Silvetti 8/7/12

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

void setup() {
  lcd.begin(LCD_WIDTH, LCD_HEIGHT);
  Serial.begin(9600);
  pinMode(infrarosso, INPUT);
  pinMode(2, OUTPUT); 
  pinMode(1, OUTPUT);

  
  // The internal 1.1V reference provides for better
  // resolution from the LM35, and is also more stable
  // when powered from either a battery or USB...
  analogReference(INTERNAL);
}


void loop() {
  // Start beyond the edge of the screen...
  static byte xChart = LCD_WIDTH;
  
    // read the input on analog pin 0:
  int sensorValue = analogRead(A1);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
 
  //se il valore è maggiore di 100 inizia la memorizzazione del segnale 
  //in un array di 4 elementi
    if(sensorValue>500){
      digitalWrite(2, HIGH);
        //ciclo for per la memorizzazione dei degnali

        
        
        for(int i=0; i<4; i++){ 
                if(analogRead(A1)>520){  
                  value[i]=1;
                }
                else{
                value[i]=0;
                }
        lcd.setCursor(0, 0);
        lcd.print("i[0]=");
        lcd.println(value[0]);
        lcd.setCursor(0, 1);
        lcd.print("i[1]=");
        lcd.println(value[1]);
        lcd.setCursor(0, 2);
        lcd.print("i[2]=");
        lcd.println(value[2]);
        lcd.setCursor(0, 3);
        lcd.print("i[3]=");
        lcd.println(value[3]);
        delay(RITARDO); 
        }
        
    }else{
        digitalWrite(2, LOW);
        }
  lcd.setCursor(0, 5);
  lcd.print("value=");
  lcd.println(sensorValue);
  
  
  if(value[0]==1 && value[1]==0 && value[2]==0 && value[3]==0){
   
  }
  else if(value[0]==1 && value[1]==0 && value[2]==1 && value[3]==1){
  
  }
}
