#include "./Wall.h"

Wall::Wall(int x, int y, int width, int height) {
  _x = x;
  _y = y;

  if (x < x + width) {
    _minX = x;
    _maxX = x + width;
  } else {
    _minX = x + width;
    _maxX = x;
  }

  if (y < y + height) {
    _minY = y;
    _maxY = y + height;
  } else {
    _minY = y + height;
    _maxY = y;
  }
}

int Wall::getX() {
  return _x;
}

int Wall::getY() {
  return _y;
}

bool Wall::hasCollided(Ball *ball) {
  int ballMinY = ball->getY() - ball->getRadius();
  int ballMaxY = ball->getY() + ball->getRadius();
  int ballMinX = ball->getX() - ball->getRadius();
  int ballMaxX = ball->getX() + ball->getRadius();


  // If ball to the left, or ball to the right, no collision
  if (ballMaxX < _minX || ballMinX > _maxX) {
    return false;
  }

  // If ball is "above" the box, or "below" the box, no collision
  if (ballMaxY < _minY || ballMinY > _maxY) {
    return false;
  }

  return true;
}
