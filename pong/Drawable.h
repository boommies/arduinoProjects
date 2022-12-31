#ifndef Drawable_h
#define Drawable_h

class Drawable {
public:
  virtual void draw();
  virtual void setDisplay(U8GLIB_SH1106_128X64 *display);
  virtual void setBounds(int x, int y);
};

#endif