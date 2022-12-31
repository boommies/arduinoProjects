#ifndef Wall_h
#define Wall_h
#include "./Collidable.h"
#include "./Ball.h"

class Wall: public Collidable {
public:
  Wall(int x, int y, int width, int height);
  int getX();
  int getY();
  bool hasCollided(Ball *ball);
private:
  int _minX;
  int _minY;
  int _maxX;
  int _maxY;
  int _x;
  int _y;
};

#endif