#include <Arduino.h>
#include "./EndGameState.h"

EndGameState::EndGameState(U8GLIB_SH1106_128X64 *display) {
  _display = display;
}

void EndGameState::step() {
    _display->firstPage(); 
    do {
      _display->setFont(u8g_font_unifont);
      _display->setPrintPos(30, 38);
      _display->print("Game Over");
    } while(_display->nextPage());

    delay(5000);
}
