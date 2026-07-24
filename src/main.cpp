#include <Arduino.h>

const int verd = 2;
const int amar = 3;
const int verm = 4;
const int bt = 5;

const int verdB = 6;
const int amarB = 7;
const int vermB = 8;
const int btB = 9;

const int buzzer = 10;

void tempoEbotao(int botao){

    for(int i = 0; i < 50; i++){
    int btatual = digitalRead(botao);

    if(btatual == LOW){
      break;
    }
    delay(100);
  }
}

void piscaAmarelo(int amarelo){

    for(int i = 0; i < 3; i++){
    digitalWrite(amarelo, LOW);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(amarelo, HIGH);
    digitalWrite(buzzer, LOW);
    delay(500);

  }
}

void setup(){

  Serial.begin(9600);

  pinMode(verd, OUTPUT);
  pinMode(amar, OUTPUT);
  pinMode(verm, OUTPUT);
  pinMode(bt,INPUT_PULLUP);

  pinMode(verdB, OUTPUT);
  pinMode(amarB, OUTPUT);
  pinMode(vermB, OUTPUT);
  pinMode(btB,INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);

}

void loop(){

  // ===========================
  // FUNÇÂO DO VERDE E VERMELHO
  digitalWrite(verd, HIGH); digitalWrite(vermB, HIGH);

  tempoEbotao(bt);

  digitalWrite(verd, LOW); 

  // ===========================
  //FUNÇÂO DO AMARELO E VERMELHO 

  digitalWrite(amar, HIGH); 
  delay(2000);

  piscaAmarelo(amar);

  digitalWrite(amar, LOW); digitalWrite(vermB, LOW);

  // ===========================
  //FUNÇÂO DO VERMELHO E VERDE

  digitalWrite(verm, HIGH); digitalWrite(verdB, HIGH);

  tempoEbotao(btB);

  digitalWrite(verdB, LOW); 


  // ===========================
  // FUNÇÂO DE VERMELHO E AMARELO

  digitalWrite(amarB, HIGH);
  delay(2000);

  piscaAmarelo(amarB);

  digitalWrite(verm, LOW); digitalWrite(amarB, LOW);

  // ===========================
  // E O CICLO SE REPETE DE NOVO


}