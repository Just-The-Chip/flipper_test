#pragma once
#include "Arduino.h"
#include "BasicComponent.h"
#include <stdint.h>

class TimedOutputComponent : public BasicComponent {
  public:
    TimedOutputComponent(
      int _pinIn, 
      int _pinOut,
      unsigned long _outputDuration,
      bool _inputRestValue = HIGH,
      bool _outputRestValue = LOW      
    );
    virtual void update();
    virtual bool shouldTriggerOutput();

  protected:
    unsigned long outputDuration;
    unsigned long outputOnTime;
    unsigned long lastUpdateTime;
};