#include "game.h"

Game::Game(int sH, int sW, Font f) {
    sHeight = sH;
    sWidth = sW;
    font = f;
    level = 0;
    levels = Levels();
    Init();
}


void Game::Init()
{
    ball = Ball(sWidth / 2, sHeight - 150, 15, WHITE, 7, -7, sHeight, sWidth);
    player = Paddle(sWidth / 2 - 50, sHeight - 60, 30, 100, sWidth, sHeight, WHITE);
    score = 0;
    gameover = false;
}

void Game::Update() {

    gameover = ball.Update();
    HandleInput();// handle input to move player

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



void Game::CheckLevelclear() {
    //check all bricks are 0 hp
    bool clear = levels.CheckLevel(level);
    if (clear) {// level is clear
        level++;
        Init();// restart with new level
    }
}



void Game::HandleInput() {
    int keyPressed = GetKeyPressed();
    if (gameover) {// checks for game over
        levels = Levels();// rset levels
        Init();
    }
    if (IsKeyDown(KEY_LEFT)) {
        player.MoveLeft();
    }
    if (IsKeyDown(KEY_RIGHT)) {
        player.MoveRight();
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


