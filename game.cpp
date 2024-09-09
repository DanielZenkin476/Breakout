#include "game.h"
// for move between levels- to make a single press possible 
double lastUpdateTime = 0.0;// to manage block movment downwards

bool EventTriggered(double interval) {// to check if interval is less then 2 msec- then new hit
    // function to check if time between current time and last check time is more then interval- if yes return true
    double currTime = GetTime();
    if (interval <= currTime - lastUpdateTime) {
        lastUpdateTime = currTime;
        return true;
    }
    return false;
}



//------------

Game::Game(int sH, int sW, Font f) {
    sHeight = sH;
    sWidth = sW;
    font = f;
    level = 0;
    levels = Levels();
    score = 0;
    Init();
}


void Game::Init()
{
    ball = Ball(sWidth / 2, sHeight - 150, 15, WHITE, 7, -7, sHeight, sWidth);
    player = Paddle(sWidth / 2 - 50, sHeight - 60, 30, 100, sWidth, sHeight, WHITE);
    gameover = false;
    currLevel = levels.GetLevels(level);
}

void Game::Update() {

    gameover = ball.Update();
    HandleInput();// handle input to move player

}

void Game::CollDetect() {
    // coll detection with player
    ball.CollDetect(player);

    // coll detection with brick
    for (int i = 0; i < currLevel.size(); i++) {
        if (ball.CollDetectBrick(currLevel[i])) {
            score += currLevel[i].Hit();
        }
        currLevel[i].Draw();// draw the brick after collision check and score update- can do here because las func before draw - not the best place but more efficent then an extra loop
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
    if (gameover && IsKeyDown) {// checks for game over
        levels = Levels();// rset levels
        Init();
    }
    if (IsKeyDown(KEY_LEFT)) {
        player.MoveLeft();
    }
    if (IsKeyDown(KEY_RIGHT)) {
        player.MoveRight();
    }
    if (IsKeyDown(KEY_UP)) {
        if (EventTriggered(1.0)) {
            level = (level+1)%3;
            Init();
        }
        
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


