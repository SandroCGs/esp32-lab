#include <Arduino.h>

void setup() {
  pinMode(15 ,OUTPUT);
  pinMode(16 ,OUTPUT);
  pinMode(17 ,OUTPUT);
  pinMode(18 ,OUTPUT); 
}

void loop() {
  int saidaPot = analogRead(10);

  if(saidaPot < 809){ 
    digitalWrite(15, LOW);
  }
  if(saidaPot >= 809){ /*eu podia ter feito com else, ia ficar menos feio*/ 
    digitalWrite(15, HIGH);
  }

  if(saidaPot >= 1618){
    digitalWrite(16, HIGH);
  }
  if(saidaPot < 1618){
    digitalWrite(16, LOW);
  }

  if(saidaPot >= 2427){
    digitalWrite(17, HIGH);
  }
  if(saidaPot < 2427){
    digitalWrite(17, LOW);
  }

  if(saidaPot >= 3236){
    digitalWrite(18, HIGH);
  }
  if(saidaPot < 3236){
    digitalWrite(18, LOW);
  }
}
