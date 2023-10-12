#include "Arduino.h"
#include "Slingshot.h"

Slingshot::Slingshot(int _switchPin, int _kickerPin) {
  switchPin = _switchPin;
  kickerPin = _kickerPin;

  pinMode(switchPin, INPUT_PULLUP);
  pinMode(kickerPin, OUTPUT);
}

void Slingshot::update() {
  if(switchActivated()) {
    digitalWrite(kickerPin, LOW);
  } else {
    digitalWrite(kickerPin, HIGH);
  }
}

bool Slingshot::switchActivated() {
  return !digitalRead(switchPin);
}