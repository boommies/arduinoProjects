#ifndef StartGameState_h
#define StartGameState_h

#include <U8glib.h>

class StartGameState {
public:
  StartGameState(U8GLIB_SH1106_128X64 *display);
  void step();
  bool hasGameStarted();
  void reset();
private:
  U8GLIB_SH1106_128X64 *_display;
  bool _hasStarted;
};

#endif