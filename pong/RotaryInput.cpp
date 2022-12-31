#include <Arduino.h>
#include "./RotaryInput.h"

RotaryInput::RotaryInput(uint8_t clockPin, uint8_t dataPin) {
  _clockPin = clockPin;
  _dataPin = dataPin;
  _magnitude = 0;
}

void RotaryInput::updateMagnitude() {
  // Read the current state of CLK
  _currentStateCLK = digitalRead(_clockPin);
 
  // If last and current state of CLK are different, then a pulse occurred;
  // React to only 0->1 state change to avoid double counting
  if (_currentStateCLK != _lastStateCLK  && _currentStateCLK == 1){
 
    // If the DT state is different than the CLK state then
    // the encoder is rotating CW so INCREASE counter by 1
    if (digitalRead(_dataPin) != _currentStateCLK) {
      if (_currentDir != "CW") {
        _magnitude = 0;
      }
      
      _magnitude++;
      _currentDir ="CW";
     
    } else {
      if (_currentDir != "CCW") {
        _magnitude = 0;
      }

      // Encoder is rotating CCW so DECREASE counter by 1
      _magnitude--;
      _currentDir ="CCW";
    }

    _userFunc(_magnitude);
  }
 
  // Remember last CLK state to use on next interrupt...
  _lastStateCLK = _currentStateCLK;
}

void RotaryInput::setup(void (*updateMagnitude)(void), void (*userFunc)(int magnitude)) {
  _userFunc = userFunc;
  _updateMagnitude = updateMagnitude;
  
  pinMode(_clockPin, INPUT);
  pinMode(_dataPin, INPUT);

  _lastStateCLK = digitalRead(_clockPin);

  attachInterrupt(digitalPinToInterrupt(_clockPin), _updateMagnitude, CHANGE);
  attachInterrupt(digitalPinToInterrupt(_dataPin), _updateMagnitude, CHANGE);
}