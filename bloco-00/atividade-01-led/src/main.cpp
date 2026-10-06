#include <Arduino.h>

unsigned long tempoAnterior = 0;
unsigned long intervalo = 1000;
int i = 1;

void setup() {
  pinMode(21, OUTPUT);
  
}

void loop() {
  //digitalWrite(21, HIGH);
  //delay(1000);
  //digitalWrite(21, LOW);
  //delay(1000);
  
  // a diferença entre o delay e o millis(), que pega o tempo atual, é a de que
  // delay trava o código até ele o delay concluir. Se eu tivesse colocado um botão,
  // ele não seria lido enquanto estivesse no delay. Coisa que não vai acontecer
  // no uso do millis

  unsigned long tempoAtual = millis();
  if(tempoAtual - tempoAnterior >= intervalo){
    tempoAnterior = tempoAtual;
    if(i == 1){
      digitalWrite(21, HIGH);
      i = 0;
    } else {
      digitalWrite(21, LOW);
      i = 1;
    }
  }
}