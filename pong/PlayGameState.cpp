#include <Arduino.h>
#include "./PlayGameState.h"
#include "./Paddle.h"
#include "./Ball.h"
#include "./Canvas.h"
#include "./RotaryInput.h"
#include "./Wall.h"

PlayGameState::PlayGameState(Canvas *_canvas, Paddle *_paddle, Ball *_ball, Wall *_leftWall, Wall *_rightWall, Wall *_topWall, Wall *_bottomWall, RotaryInput *_rotaryInput) {
  canvas = _canvas;
  paddle = _paddle;
  ball = _ball;
  leftWall = _leftWall;
  rightWall = _rightWall;
  topWall = _topWall;
  bottomWall = _bottomWall;
  rotaryInput = _rotaryInput;
  gameOver = false;
}

void PlayGameState::setup(void (*updateMagnitude)(void), void (*userFunc)(int magnitude)) {
  Serial.begin(9600);
  canvas->add(paddle);
  canvas->add(ball);
  
  randomSeed(analogRead(0));
  ball->setX(paddle->getX() + paddle->getWidth() + 10 + random(20));
  ball->setY(ball->getRadius() + random(64 - ball->getRadius()));

  RotaryInput *myRotary = rotaryInput;
  Paddle *myPaddle = paddle;

  rotaryInput->setup(updateMagnitude, userFunc);
}

void PlayGameState::updateMagnitude() {
  rotaryInput->updateMagnitude();
}

void PlayGameState::movePaddle(int magnitude) {
  paddle->move(magnitude);
}

void PlayGameState::step() {
  canvas->draw();
  ball->step();

  if (paddle->hasCollided(ball)) {
    ball->setX(paddle->getX() + paddle->getWidth() + ball->getRadius());
    ball->reverseDeltaX();
  }

  if (topWall->hasCollided(ball)) {
    ball->setY(topWall->getY() + ball->getRadius());
    ball->reverseDeltaY();
  }

  if (bottomWall->hasCollided(ball)) {
    ball->setY(bottomWall->getY() - ball->getRadius());
    ball->reverseDeltaY();
  }

  if (rightWall->hasCollided(ball)) {
    ball->setX(rightWall->getX() - ball->getRadius());
    ball->reverseDeltaX();
  }

  if (leftWall->hasCollided(ball)) {
    gameOver = true;
  }
}

bool PlayGameState::isGameOver() {
  return gameOver;
}

void PlayGameState::reset() {
  gameOver = false;

  ball->reset();
  randomSeed(analogRead(0));
  ball->setX(paddle->getX() + paddle->getWidth() + 10 + random(20));
  ball->setY(ball->getRadius() + random(64 - ball->getRadius()));
}
