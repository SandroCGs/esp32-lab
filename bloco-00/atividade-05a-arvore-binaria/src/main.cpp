#include <Arduino.h>
//2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 21, 47
  //lado esquerdo
  int L1_S = 4;
  int L2_SS = 5;
  int L3_SSS = 6;
  int L3_SSN = 16;
  int L2_SN = 15;
  int L3_SNS = 7; 
  int L3_SNN = 17;

  //lado direito
  int L1_N = 8;
  int L2_NS = 9;
  int L3_NSS = 10;
  int L3_NSN = 11;
  int L2_NN = 12;
  int L3_NNS = 13;
  int L3_NNN = 14;

  int vazio = -1;

  //int ledsSim[] = {L1_S, L2_SS, L3_SSS, L3_SNS, L2_NS, L3_NSS, L3_NNS};
  //int ledsNao[] = {L1_N, L2_SN, L3_SSN, L3_SNN, L2_NN, L3_NSN, L3_NNN};
  int leds[] = {vazio, L1_S, L1_N, L2_SS, L2_SN, L2_NS, L2_NN, L3_SSS, L3_SSN, L3_SNS, L3_SNN, L3_NSS, L3_NSN, L3_NNS, L3_NNN};
  int tamanhoLeds = sizeof(leds)/sizeof(leds[0]);
  int valores[] = {3, 4, 5};
  int tamanho = sizeof(valores)/sizeof(valores[0]);
  
  void recursiva(/*int *leds,*/ int *valores, int tamanho, int soma){
        //print --1
        //print inverso --0
        //12 9 8 5 7 4 3 0
        if(tamanho == 0){
          if(soma == 12){
            digitalWrite(L3_SSS, HIGH);
            delay(200);
            digitalWrite(L3_SSS, LOW);
          }
          if(soma == 9){
            digitalWrite(L3_SSN, HIGH);
            delay(200);
            digitalWrite(L3_SSN, LOW);
          }
          if(soma == 8){
            digitalWrite(L3_SNS, HIGH);
            delay(200);
            digitalWrite(L3_SNS, LOW);
          }
          if(soma == 5){
            digitalWrite(L3_SNN, HIGH);
            delay(200);
            digitalWrite(L3_SNN, LOW);
          }
          if(soma == 7){
            digitalWrite(L3_NSS, HIGH);
            delay(200);
            digitalWrite(L3_NSS, LOW);
          }
          if(soma == 4){
            digitalWrite(L3_NSN, HIGH);
            delay(200);
            digitalWrite(L3_NSN, LOW);
          }
          if(soma == 3){
            digitalWrite(L3_NNS, HIGH);
            delay(200);
            digitalWrite(L3_NNS, LOW);
          }
          if(soma == 0){
            digitalWrite(L3_NNN, HIGH);
            delay(200);
            digitalWrite(L3_NNN, LOW);
          }
          return;
        }
        recursiva(valores, tamanho-1, soma + valores[tamanho-1]);
        recursiva(valores, tamanho-1, soma + 0);
  }

void setup() {
  for(int i = 1; i < tamanhoLeds; i++){
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  recursiva(valores, tamanho, 0);
}

