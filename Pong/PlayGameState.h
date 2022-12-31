#ifndef PlayGameState_h
#define PlayGameState_h

#include "./Canvas.h"
#include "./Paddle.h"
#include "./Ball.h"
#include "./Wall.h"
#include "./RotaryInput.h"


class PlayGameState {
public:
  PlayGameState(Canvas *canvas, Paddle *paddle, Ball *ball, Wall *leftWall, Wall *rightWall, Wall *topWall, Wall *bottomWall, RotaryInput *rotaryInput);
  void setup(void (*updateMagnitude)(void), void (*userFunc)(int magnitude));
  void step();
  void updateMagnitude();
  void movePaddle(int magnitude);
  bool isGameOver();
  void reset();
private:
  Canvas *canvas;
  Paddle *paddle;
  Ball *ball;
  Wall *leftWall;
  Wall *topWall;
  Wall *rightWall;
  Wall *bottomWall;
  RotaryInput *rotaryInput;
  bool gameOver;
};

#endif