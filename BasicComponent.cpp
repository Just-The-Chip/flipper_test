#include "HardwareSerial.h"
#include "Arduino.h"
#include "BasicComponent.h"

BasicComponent::BasicComponent(int _pinIn, int _pinOut, bool _inputRestValue, bool _outputRestValue) {
  pinIn = _pinIn;
  pinOut = _pinOut;
  inputRestValue = _inputRestValue;
  outputRestValue = _outputRestValue;

  pinMode(pinIn, INPUT_PULLUP);
  pinMode(pinOut, OUTPUT);
}

void BasicComponent::update() {
  if(shouldTriggerOutput()) {
    // if (pinIn == 33) {
    //   Serial.println(!outputRestValue);
    // }
    digitalWrite(pinOut, !outputRestValue);
  } else {
    digitalWrite(pinOut, outputRestValue);
  }
}

bool BasicComponent::shouldTriggerOutput() {
  return inputActivated();
}

bool BasicComponent::inputActivated() {
  // if (pinIn == 33) {
  //   Serial.print("input rest value: ");
  //   Serial.println(inputRestValue);

  //   Serial.print("output rest value: ");
  //   Serial.println(outputRestValue);
  // }
  bool pinVal = digitalRead(pinIn);
  return inputRestValue == LOW ? pinVal : !pinVal;
}