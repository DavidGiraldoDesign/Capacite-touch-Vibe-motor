#include "pitches.h"
int inicio_notas[] = {
  NOTE_C5, NOTE_E5, NOTE_E5, NOTE_D4, NOTE_D5, NOTE_C4
};
int inicio_tiempos[] = {
  2, 4, 3, 4, 3, 2
};
boolean sound = true;
int pinTouch = 2;
int pinVibe = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinTouch, INPUT);
  pinMode(pinVibe, OUTPUT);
  Serial.begin(9600);
  playTono(inicio_notas, inicio_tiempos, 6, 0.7);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(pinTouch));

  if (digitalRead(pinTouch) == HIGH) {
    for (int i = 50; i < 200; i++) {
      analogWrite(pinVibe, i);
      delay(10);
    }
    digitalWrite(pinVibe, LOW);
    delay(1000);

  } else {
    digitalWrite(pinVibe, LOW);
  }
  delay(100);
}


void playTono(int notas[], int tiempos[], int tam, float tempo) {
  if (sound == true) {
    for (int nota = 0; nota < tam; nota++) {
      int tiempo = 1000 / tiempos[nota];
      tone(8, notas[nota], tiempo);
      int pauseBetweenNotes = tiempo * tempo;
      delay(pauseBetweenNotes);
      noTone(8);
    }
  }

}
