#ifndef EndGameState_h
#define EndGameState_h

#include <U8glib.h>

class EndGameState {
public:
  EndGameState(U8GLIB_SH1106_128X64 *display);
  void step();
private:
  U8GLIB_SH1106_128X64 *_display;
};

#endif