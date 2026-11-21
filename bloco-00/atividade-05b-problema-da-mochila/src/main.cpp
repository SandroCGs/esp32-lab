#include <Arduino.h>

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

int leds[] = {vazio, L1_S, L1_N, L2_SS, L2_SN, L2_NS, L2_NN, L3_SSS, L3_SSN, L3_SNS, L3_SNN, L3_NSS, L3_NSN, L3_NNS, L3_NNN};
int tamanhoLeds = sizeof(leds) / sizeof(leds[0]);

int valores[] = {3, 4, 5};
int pesos[] = {2, 3, 4};
int tamanho = sizeof(valores) / sizeof(valores[0]);

void mostrarNumero(int numero) {
    if (numero < 0 || numero > 9) return; 

    digitalWrite(pino_A, (numero >> 0) & 0x01);
    digitalWrite(pino_B, (numero >> 1) & 0x01);
    digitalWrite(pino_C, (numero >> 2) & 0x01);
    digitalWrite(pino_D, (numero >> 3) & 0x01);
}

void apagarNumero() {
    digitalWrite(pino_A, HIGH);
    digitalWrite(pino_B, HIGH);
    digitalWrite(pino_C, HIGH);
    digitalWrite(pino_D, HIGH);
}

void recursiva(int *valores, int *pesos, int indice, int tamanho, int r, int l, int soma, int pesoTotal) {
    r = r + r + l;
  
    if(pesoTotal > 6/*poda fixa*/) {
        delay(5); 
        rgbLedWrite(RGB_BUILTIN, 20, 0, 0);
        mostrarNumero(soma - valores[indice - 1]);        
        delay(1000);
        rgbLedWrite(RGB_BUILTIN, 0, 0, 0);
        delay(500);
        return;
    }

    if (l != 0) {
        digitalWrite(leds[r], HIGH);
        mostrarNumero(soma);
        if(indice == tamanho && pesoTotal <= 6){
             rgbLedWrite(RGB_BUILTIN, 0, 20, 0);
        }
        delay(1000);
        rgbLedWrite(RGB_BUILTIN, 0, 0, 0);
    }

    if (indice < tamanho) {
        recursiva(valores, pesos, indice + 1, tamanho, r, 1, soma + valores[indice], pesoTotal + pesos[indice]); //sim
        recursiva(valores, pesos, indice + 1, tamanho, r, 2, soma, pesoTotal);//nao
    }

    if (l != 0) {
        digitalWrite(leds[r], LOW);
        if (l == 1) {
            mostrarNumero(soma - valores[indice - 1]);
        } else {
            mostrarNumero(soma);
        }
        delay(600);
    }
}

void setup() {
    for (int i = 1; i < tamanhoLeds; i++) {
        pinMode(leds[i], OUTPUT);
    }

    pinMode(pino_A, OUTPUT);
    pinMode(pino_B, OUTPUT);
    pinMode(pino_C, OUTPUT);
    pinMode(pino_D, OUTPUT);
}

void loop() {
    apagarNumero();
    delay(1000);
    recursiva(valores, pesos, 0, tamanho, 0, 0, 0, 0);
}