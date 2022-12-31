#include <U8glib.h>
#include "./Paddle.h"
#include "./Ball.h"
#include "./Canvas.h"
#include "./RotaryInput.h"
#include "./Wall.h"
#include "./StartGameState.h"
#include "./PlayGameState.h"
#include "./EndGameState.h"

U8GLIB_SH1106_128X64 display(U8G_I2C_OPT_NONE);
Canvas canvas(128, 64, &display);
Paddle paddle;
Ball ball;
Wall leftWall(0,0, -64, 128);
Wall rightWall(128, 0, 64, 64);
Wall topWall(0, 0, 128, -64);
Wall bottomWall(0, 64, 128, 64);
RotaryInput rotaryInput(2, 3);

StartGameState startGameState(&display);
PlayGameState playGameState(&canvas, &paddle, &ball, &leftWall, &rightWall, &topWall, &bottomWall, &rotaryInput); 
EndGameState endGameState(&display);

void setup(void) {
  auto updateMagnitude = [playGameState] () { playGameState.updateMagnitude(); };
  auto updatePaddleSpeed = [playGameState] (int magnitude) { playGameState.movePaddle(magnitude); }; 
  playGameState.setup(updateMagnitude, updatePaddleSpeed);
}

void loop(void) {
  if (!startGameState.hasGameStarted()) {
    startGameState.step();
  } 

  if (!playGameState.isGameOver()) {
    playGameState.step();
  } else {
    endGameState.step();

    //startGameState.reset();
    playGameState.reset();
  }
}

