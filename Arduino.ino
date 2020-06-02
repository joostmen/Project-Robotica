const int Tx = 3;
const int Rx = 4;
const int echo = 12;
const int trig = 11;
int ontvangst;
char afstand;
int duur;

void setup() {
  pinMode(trig, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo, INPUT); // Sets the echoPin as an Input
  pinMode(Tx, OUTPUT);
  pinMode(Rx, INPUT);
  Serial.begin(9600); // Starts the serial communication

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Rx==1){
    delay(1);
    if(Rx==1){
      int i;
      for (i = 0; i < 13; i++){
        delay(1);
        ontvangst = ontvangst >> 1;
        ontvangst = ontvangst + Rx;
      }
      if(ontvangst & 100000000000){
        leesSensor();
      }
    }const int Tx = 3;
const int Rx = 4;
const int echo = 12;
const int trig = 11;
int ontvangst;
char afstand;
int duur;

void setup() {
  pinMode(trig, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo, INPUT); // Sets the echoPin as an Input
  pinMode(Tx, OUTPUT);
  pinMode(Rx, INPUT);
  Serial.begin(9600); // Starts the serial communication

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Rx==1){
    delay(1);
    if(Rx==1){
      int i;
      for (i = 0; i < 13; i++){
        delay(1);
        ontvangst = ontvangst >> 1;
        ontvangst = ontvangst + Rx;
      }
      if(ontvangst & 100000000000){
        leesSensor();
      }
    }
    delay(20);
  }
  
}

void leesSensor(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
  duur = pulseIn(echo, HIGH);
// Calculating the distance
  afstand = duur*0.034/2;
 
  Serial.print("AfstandInCM: ");
  Serial.println(afstand);
}

void stuurAntwoord(){
  digitalWrite(Tx, HIGH);
  delayMicroseconds(5);
  digitalWrite(Tx, LOW);
  for(int i = 0; i < 8; i++){
    if((afstand >> i) == 1){
      digitalWrite(Tx, HIGH);
      delayMicroseconds(10);
    }else{
      digitalWrite(Tx, HIGH);
      delayMicroseconds(5);
    }
  }
}

    delay(20);
  }
  
}

void leesSensor(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
  duur = pulseIn(echo, HIGH);
// Calculating the distance
  afstand = duur*0.034/2;
 
  Serial.print("AfstandInCM: ");
  Serial.println(afstand);
}

void stuurAntwoord(){
  digitalWrite(Tx, HIGH);
  delayMicroseconds(5);
  digitalWrite(Tx, LOW);
  for(int i = 0; i < 8; i++){
    if((afstand >> i) == 1){
      digitalWrite(Tx, HIGH);
      delayMicroseconds(10);
    }else{
      digitalWrite(Tx, HIGH);
      delayMicroseconds(5);
    }
  }
}
