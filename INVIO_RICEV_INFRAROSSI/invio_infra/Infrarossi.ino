#define I2 3
#define I1 2
#define A 13
#define B 12
#define C 11
#define D 10
#define time 500

void setup() {  
  Serial.begin(9600);
  pinMode(A, INPUT);  
  digitalWrite(A, LOW);
  
  pinMode(B, INPUT);  
  digitalWrite(B, LOW);
  
  pinMode(C, INPUT);  
  digitalWrite(C, LOW);
  
  pinMode(D, INPUT);  
  digitalWrite(D, LOW);
  
  pinMode(I1,OUTPUT);
  pinMode(I2,OUTPUT);
  
  digitalWrite(I1, LOW);
  digitalWrite(I2, LOW);
}  

void loop() { 
     int av = digitalRead(A);
   int bv = digitalRead(B);
   int cv = digitalRead(C);
   int dv = digitalRead(D);
   
   Serial.print(av);
   Serial.print(", ");
   Serial.print(bv);
   Serial.print(", ");
   Serial.print(cv);
   Serial.print(", ");
   Serial.print(dv);
   Serial.println("");
   
   
   if(av == 1){
      digitalWrite(I1, HIGH);
      digitalWrite(I2, HIGH);
      delay(time);
      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
      delay(time);
      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
      delay(time);
      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
      delay(time);
      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
   }
   else if(bv == 1){
      digitalWrite(I1, HIGH);
      digitalWrite(I2, HIGH);
      delay(time);
      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
      delay(time);
      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
      delay(time);
      digitalWrite(I1, HIGH);
      digitalWrite(I2, HIGH);
      delay(time);
      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
   }
   else if(cv == 1){
      digitalWrite(I1, HIGH);
      digitalWrite(I2, HIGH);
      delay(time);
      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
      delay(time);
      digitalWrite(I1, HIGH);
      digitalWrite(I2, HIGH);
      delay(time);
      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
      delay(time);
      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
   }
   else if(dv == 1){
      digitalWrite(I1, HIGH);
      digitalWrite(I2, HIGH);
      delay(time);
      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
      delay(time);
      digitalWrite(I1, HIGH);
      digitalWrite(I2, HIGH);
      delay(time);
      digitalWrite(I1, HIGH);
      digitalWrite(I2, HIGH);
      delay(time);
      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
   }

}

