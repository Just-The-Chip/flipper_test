#include "HardwareSerial.h"
#include "Arduino.h"
// #include "BasicComponent.h"
#include "TimedOutputComponent.h"

TimedOutputComponent::TimedOutputComponent(int _pinIn, int _pinOut, unsigned long _outputDuration, bool _inputRestValue, bool _outputRestValue) :
  BasicComponent(_pinIn, _pinOut, _inputRestValue, _outputRestValue) {

  outputDuration = _outputDuration;
  outputOnTime = 0;
}

void TimedOutputComponent::update() {
  lastUpdateTime = millis();

  // if(inputActivated() && outputDuration == 50) {
  //   Serial.println("ON");
  // }

  if(inputActivated() && outputOnTime == 0) {
    outputOnTime = lastUpdateTime;
  }

  BasicComponent::update();

  if (!shouldTriggerOutput()) {
    outputOnTime = 0;
  }
}

bool TimedOutputComponent::shouldTriggerOutput() {
  bool shouldTrigger = outputOnTime + outputDuration >= lastUpdateTime;
  // if (outputDuration == 50 && shouldTrigger) {
  //   Serial.println(outputOnTime);
  // } else if(outputDuration == 50) {
  //   Serial.println("--");
  // }
  return shouldTrigger;
}