#include <Arduino.h>

unsigned long tempoDebounce = 10;
int estadoEstavel = HIGH;
int ultimoEstadoBruto = HIGH;
unsigned long tempoUltimaMudanca = 0;

void setup() {
  pinMode(21, INPUT);
  pinMode(4, OUTPUT);
}

/*
void loop() {
  if(digitalRead(21) == LOW){
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }
}
sem debounce
*/

void loop(){
  int estadoBruto = digitalRead(21);

  if(estadoBruto != ultimoEstadoBruto){
    tempoUltimaMudanca = millis(); //assim se mudar vai reiniciar a contagem
    ultimoEstadoBruto = estadoBruto;
  }
  
  if(millis() - tempoUltimaMudanca >= tempoDebounce){
    if(estadoBruto != estadoEstavel){
      estadoEstavel = estadoBruto;

      if(estadoEstavel == LOW){
        digitalWrite(4, HIGH);
      } else {
        digitalWrite(4, LOW);
      }
    }
  }
}