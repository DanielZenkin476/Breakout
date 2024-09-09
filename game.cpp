#include "game.h"

Game::Game(int sH, int sW, Font f) {
    sHeight = sH;
    sWidth = sW;
    font = f;
    ball = Ball(sWidth / 2, sHeight - 150, 15, WHITE, 7, -7, sHeight, sWidth);
    player = Paddle(sWidth / 2 - 50, sHeight - 60, 30, 100, sWidth, sHeight, WHITE);
    score = 0;
    levels = Levels();
    level = 2;
}


void Game::Init()
{

}

void Game::Update() {
    ball.Update();
    player.Update();
}

void Game::CollDetect() {
    // coll detection with player
    ball.CollDetect(player);

    // coll detection with brick
    for (int i = 0; i < 100; i++) {
        if (ball.CollDetectBrick(levels.levels[level][i])) {
            score += levels.levels[level][i].Hit();
        }
        levels.levels[level][i].Draw();// draw the brick after collision check and score update
    }
}


void Game::Draw() {

    // draw score:
    DrawTextEx(font, "Score", { 50,700 }, 38, 2, WHITE);// draw Score
    // drawing the score
    char scoreText[10];
    sprintf_s(scoreText, "%d", score);
    Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
    DrawTextEx(font, scoreText, { 100 + (170 - textSize.x) / 2,700 }, 38, 2, WHITE);//draw score centered


    player.Draw();
    ball.Draw();
}


