#include <Arduino.h>
#include "./Canvas.h"
#include <U8glib.h>


Canvas::Canvas(uint8_t width, uint8_t height, U8GLIB_SH1106_128X64 *display) {
  _width = width;
  _height = height;
  _display = display;
  _drawableCount = 0;

  // flip screen, if required
  //u8g.setRot180(); 

  _display->setFont(u8g_font_6x10);
  _display->setFontRefHeightExtendedText();
  _display->setDefaultForegroundColor();
  _display->setFontPosTop();
}

void Canvas::add(Drawable *drawable) {
  drawable->setDisplay(_display);
  drawable->setBounds(128, 64);
  _drawables[_drawableCount] = drawable;
  _drawableCount++;
}

void Canvas::draw() {
  _display->firstPage();  
  do {
    for(int i=0; i < _drawableCount; i++) {
      _drawables[i]->draw();
    }
  } while( _display->nextPage() );
  // iterate through objects and call draw
}

