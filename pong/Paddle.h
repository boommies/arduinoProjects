#ifndef Paddle_h
#define Paddle_h
#include <U8glib.h>
#include "./Drawable.h"
#include "./Ball.h"

class Paddle: public Drawable {
public:
  Paddle();
  void setDisplay(U8GLIB_SH1106_128X64 *display);
  void setX(int x);
  void setY(int y);
  void setBounds(int x, int y);
  int getWidth();
  int getX();
  int getMaxY();
  int move(int distance);
  void draw();
  bool hasCollided(Ball *ball);
private:
  int _y;
  int _x;
  int _maxY;
  uint8_t _width;
  uint8_t _height;
  U8GLIB_SH1106_128X64 *_display;
};
#endif