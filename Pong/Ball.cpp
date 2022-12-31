#include <Arduino.h>
#include <U8glib.h>
#include "./Ball.h"

Ball::Ball() { 
  _x = 20;
  _y = 20;
  _radius = 3;
  _deltaX = 5;
  _deltaY = 5;
}

void Ball::setDisplay(U8GLIB_SH1106_128X64 *display) {
  _display = display;
}

void Ball::setX(int x) {
    _x = x;
}

void Ball::setY(int y) {
    _y = y;
}

void Ball::setBounds(int x, int y) {
  _maxX = x - (_radius + 1);
  _maxY = y - (_radius + 1);
}

void Ball::step() {
  setX(_x + _deltaX);
  setY(_y + _deltaY);
}

void Ball::draw() {
  _display->drawDisc(_x, _y, _radius);
}

int Ball::getX() {
  return _x;
}

int Ball::getY() {
  return _y;
}

int Ball::getRadius() {
  return _radius;
}

int Ball::reverseDeltaY() {
  _deltaY = _deltaY * -1;
  return _deltaY;
}

int Ball::reverseDeltaX() {
  _deltaX = _deltaX * -1;
  return _deltaX;
}

void Ball::reset() {
  _deltaX = 5;
  _deltaY = 5;
}


