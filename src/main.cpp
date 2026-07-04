#include <Arduino.h>

const int verm = 5;
const int amar = 4;
const int verd = 3;
const int bt = 2;

void setup(){
  Serial.begin(9600);
  pinMode(verm, OUTPUT);
  pinMode(amar, OUTPUT);
  pinMode(verd, OUTPUT);
  pinMode(bt, INPUT_PULLUP);
  
}

void loop(){

  digitalWrite(verd, HIGH);
  delay(5000);
  digitalWrite(verd, LOW);
  
  for(int i = 0; i < 3; i++){
    digitalWrite(amar, HIGH);
    delay(500);
    digitalWrite(amar, LOW);
    delay(500);

  }

  digitalWrite(verm, HIGH);
  delay(5000);
  digitalWrite(verm, LOW);



}