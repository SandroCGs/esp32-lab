#include <Arduino.h>

int frequencia = 5000;
int pino = 15;
int resolucao = 8; // 8 = 0/255 10 = 0/1023

void setup() {
  //pinMode(pino, OUTPUT); não precisa, o ledcWrite vai controlar o pino
  ledcAttach(pino, frequencia, resolucao);
}

void loop() {
  int entrada = analogRead(10);
  int intensidade = entrada / 16; //x = 4095/255 == 16. Cada entrada 16 entradas represntam 1 intesidade das 255
  ledcWrite(pino, intensidade);
}
