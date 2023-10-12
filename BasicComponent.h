#pragma once
#include "Arduino.h"
#include <stdint.h>

class BasicComponent {
  public:
    BasicComponent(
      int _pinIn, 
      int _pinOut,
      bool _inputRestValue = HIGH,
      bool _outputRestValue = LOW      
    );
    virtual void update();
    virtual bool shouldTriggerOutput();
    virtual bool inputActivated();

  protected:
    int	pinIn;
    int	pinOut;
    bool inputRestValue;
    bool outputRestValue;
  };