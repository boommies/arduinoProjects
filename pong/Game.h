#ifndef Game_h
#define Game_h

#include "./GameState.h"
#include <U8glib.h>

class Game {
public:
  Game(U8GLIB_SH1106_128X64 *display);
  void step();
private:
  GameState *_currentState;
};

#endif