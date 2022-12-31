#ifndef RotaryInput_h
#define RotaryInput_h
class RotaryInput {
public:
  RotaryInput(uint8_t clockPin, uint8_t dataPin);
  void setup(void (*updateMagnitude)(void), void (*userFunc)(int magnitude));
  void updateMagnitude();
private:
  uint8_t _clockPin;
  uint8_t _dataPin;
  int _lastStateCLK;
  int _currentStateCLK;
  int _magnitude;
  String _currentDir;
  void (*_updateMagnitude)(void);
  void (*_userFunc)(int magnitude);
};
#endif