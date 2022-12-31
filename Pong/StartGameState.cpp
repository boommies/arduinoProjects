#include <Arduino.h>
#include "./StartGameState.h"

StartGameState::StartGameState(U8GLIB_SH1106_128X64 *display) {
  _display = display;
  _hasStarted = false;
}

void StartGameState::step() {
    _display->firstPage(); 
    do {
      _display->setFont(u8g_font_unifont);
      _display->setPrintPos(35, 23);
      _display->print("Welcome");
      _display->setPrintPos(54, 38);
      _display->print("to");
      _display->setPrintPos(47, 53);
      _display->print("Pong");
    } while(_display->nextPage());

    _hasStarted = true;
    delay(5000);
}

bool StartGameState::hasGameStarted() {
  return _hasStarted;
}

void StartGameState::reset() {
  _hasStarted = false;
}
