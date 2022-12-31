#ifndef Canvas_h
#define Canvas_h
#include <U8glib.h>
#include "./Drawable.h"

class Canvas {
public:
  Canvas(uint8_t width, uint8_t height, U8GLIB_SH1106_128X64 *display);
  void add(Drawable *drawable);
  void draw();
private:
  uint8_t _width;
  uint8_t _height;
  U8GLIB_SH1106_128X64 *_display;
  uint8_t _drawableCount;
  Drawable *_drawables[10];
};
#endif