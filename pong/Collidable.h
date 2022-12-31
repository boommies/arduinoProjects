#ifndef Collidable_h
#define Collidable_h

#include "./Ball.h"

class Collidable {
public:
  virtual bool hasCollided(Ball *ball);
};

#endif