#include <Arduino.h>
#include "./Paddle.h"

Paddle::Paddle() {
  _x = 10;
  _y = 10;
  _width = 3;
  _height = 20;
}

void Paddle::setDisplay(U8GLIB_SH1106_128X64 *display) {
  _display = display;
}

void Paddle::setX(int x) {
  _x = x;
}

void Paddle::setY(int y) {
  _y = y;
}

int Paddle::move(int distance) {
  if ((_y + distance) >= _maxY) {
    _y = _maxY;
  } else if ((_y + distance) < 0) {
    _y = 0;
  } else {
    _y += distance;
  }

  return _y;
}

void Paddle::setBounds(int maxX, int maxY) {
  _maxY = maxY - _height;
  return _maxY;
}

int Paddle::getX() {
  return _x;
}

int Paddle::getWidth() {
  return _width;
}

int Paddle::getMaxY() {
  return _maxY;
}

void Paddle::draw() {
  _display->drawBox(_x, _y, _width, _height);
}

bool Paddle::hasCollided(Ball *ball) {
  int ballMinY = ball->getY() - ball->getRadius();
  int ballMaxY = ball->getY() + ball->getRadius();
  int ballMinX = ball->getX() - ball->getRadius();
  int ballMaxX = ball->getX() + ball->getRadius();


  // If ball to the left, or ball to the right, no collision
  if (ballMaxX < _x || ballMinX > _x + _width) {
    return false;
  }

  // If ball is "above" the box, or "below" the box, no collision
  if (ballMaxY < _y || ballMinY > _y + _height) {
    return false;
  }

  return true;
}

