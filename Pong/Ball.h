#ifndef Ball_h
#define Ball_h
#include <U8glib.h>
#include "./Drawable.h"

class Ball: public Drawable {
public:
  Ball();
  void setDisplay(U8GLIB_SH1106_128X64 *display);
  void setX(int x);
  void setY(int y);
  void setBounds(int x, int y);
  void step();
  void draw();
  int getX();
  int getY();
  int getRadius();
  int reverseDeltaY();
  int reverseDeltaX();
  void reset();
private:
  int _x;
  int _y;
  int _deltaX;
  int _deltaY;
  int _maxX;
  int _maxY;
  uint8_t _radius;
  U8GLIB_SH1106_128X64 *_display;
};
#endif