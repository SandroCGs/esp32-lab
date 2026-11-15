#include <Arduino.h>
//2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 21, 47
//4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 
//1 2 18 21 47 
  int vazio = -1;  
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

  
  int pino_A = 18; //0
  int pino_B = 21; //1
  int pino_C = 2;  //2
  int pino_D = 47; //3

  //int ledsSim[] = {L1_S, L2_SS, L3_SSS, L3_SNS, L2_NS, L3_NSS, L3_NNS};
  //int ledsNao[] = {L1_N, L2_SN, L3_SSN, L3_SNN, L2_NN, L3_NSN, L3_NNN};
  int leds[] = {vazio, L1_S, L1_N, L2_SS, L2_SN, L2_NS, L2_NN, L3_SSS, L3_SSN, L3_SNS, L3_SNN, L3_NSS, L3_NSN, L3_NNS, L3_NNN};
  int tamanhoLeds = sizeof(leds)/sizeof(leds[0]);
  //int leds[2][7] = {
  //  {L1_S, L2_SS, L2_SN, L3_SSS, L3_SSN, L3_SNS, L3_SNN},
  //  {L1_N, L2_NS, L2_NN, L3_NSS, L3_NSN, L3_NNS, L3_NNN}
  //}; 
  //int linhasLed = sizeof(leds)/sizeof(leds[0]);
  //int colunasLed = sizeof(leds[0])/sizeof(leds[0][0]);
  
  int valores[] = {4, 3, 2};
  int tamanho = sizeof(valores)/sizeof(valores[0]);
  int soma = 0;

  //int contador = 0;
  //int *p = &contador;
  //int flag = tamanho/2;

void mostrarNumero(int numero) {
  if (numero < 0 || numero > 9) return; 

  digitalWrite(pino_A, (numero >> 0) & 0x01);
  digitalWrite(pino_B, (numero >> 1) & 0x01);
  digitalWrite(pino_C, (numero >> 2) & 0x01);
  digitalWrite(pino_D, (numero >> 3) & 0x01);
}

void apagarNumero() {
  digitalWrite(pino_A, LOW);
  digitalWrite(pino_B, LOW);
  digitalWrite(pino_C, LOW);
  digitalWrite(pino_D, LOW);
}

void recursiva(int *valores, int tamanho, int r, int l, int soma) {
  //print --1
  //print inverso --0
  //12 9 8 5 7 4 3 0
  
  r = r + r + l;
  
  if (l != 0) {
    digitalWrite(leds[r], HIGH);
    mostrarNumero(soma);
    delay(1000);
  }

  if (tamanho > 0) {
    recursiva(valores, tamanho - 1, r, 1, soma + valores[tamanho -1]); // sim
    recursiva(valores, tamanho - 1, r, 2, soma);  
  }

   if (l != 0) {
    digitalWrite(leds[r], LOW);
    if (l == 1) {
      mostrarNumero(soma - valores[tamanho]);
    } else {
      mostrarNumero(soma);
    }
    delay(1000);
  }
}


void setup() {
  for(int i = 1; i < tamanhoLeds; i++){
    pinMode(leds[i], OUTPUT);
  }

  pinMode(pino_A, OUTPUT);
  pinMode(pino_B, OUTPUT);
  pinMode(pino_C, OUTPUT);
  pinMode(pino_D, OUTPUT);
}

void loop() {
  apagarNumero();
  delay(500);
  recursiva(valores, tamanho, 0, 0, soma);
}

