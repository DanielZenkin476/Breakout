#include "game.h"
// for move between levels- to make a single press possible 
double lastUpdateTime = 0.0;// to manage block movment downwards

bool EventTriggered(double interval) {// to check if interval is less then interval sec
    // function to check if time between current time and last check time is more then interval- if yes return true, update last update time
    double currTime = GetTime();
    if (interval <= currTime - lastUpdateTime) {
        lastUpdateTime = currTime;
        return true;
    }
    return false;
}



//------------

Game::Game(int sH, int sW, Font f) {// Ctor , setups game from level 1
    sHeight = sH;
    sWidth = sW;
    font = f;
    level = 0;
    levels = Levels();
    score = 0;
    Init();
}


void Game::Init()// function that creates a new ball player and current level (used between level movments or resets)
{
    ball = Ball(sWidth / 2, sHeight - 150, 15, WHITE, 7, -7, sHeight, sWidth);
    player = Paddle(sWidth / 2 - 50, sHeight - 60, 30, 100, sWidth, sHeight, WHITE);
    gameover = false;
    currLevel = levels.GetLevels(level);
}

void Game::Update() {// Updates game objects - used every frame , updates position of paddle and ball

    gameover = ball.Update();
    HandleInput();// handle input to move player

}

void Game::CollDetect() {
    // coll detection ball with player
    ball.CollDetect(player);

    // coll detection with brick, for loop on every brick
    for (int i = 0; i < currLevel.size(); i++) {
        if (ball.CollDetectBrick(currLevel[i])) {// if hit, add scroe
            score += currLevel[i].Hit();// call upon hit function, returns score
        }
        currLevel[i].Draw();// draw the brick after collision check and score update- can do here because las func before draw - not the best place but more efficent then an extra loop
    }
}



void Game::CheckLevelclear() {// function checks if curr level is cleared ( using levels
    //check all bricks are 0 hp
    bool clear = levels.CheckLevel(level);
    if (clear) {// level is clear
        level++;//
        level = level % 3;// to make sure level stays in range
        Init();// restart with new level
    }
}



void Game::HandleInput() {// function to hanle player input and to check for game over 
    if (gameover && IsKeyDown) {// checks for game over
        levels = Levels();// reset levels
        level = 0; // go back to level 0 - can change
        score = 0;
        Init();
    }
    if (IsKeyDown(KEY_LEFT)) {// left movment
        player.MoveLeft();
    }
    if (IsKeyDown(KEY_RIGHT)) {// right movment
        player.MoveRight();
    }
    if (IsKeyDown(KEY_UP)) {// level skip - for quick check usage
        if (EventTriggered(1.0)) {
            level = (level+1)%3;// to make sure level stays in range
            Init();
        }
        
    }
}


void Game::Draw() {// function draws the score, ball and player paddle - bricks drawn when collision is checked to save a loop runtime

    // draw score:
    DrawTextEx(font, "Score", { 50,700 }, 38, 2, WHITE);// draw Score
    // drawing the score itself
    char scoreText[10];
    sprintf_s(scoreText, "%d", score);
    Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
    DrawTextEx(font, scoreText, { 100 + (170 - textSize.x) / 2,700 }, 38, 2, WHITE);//draw score centered
    // draw ball and player
    player.Draw();
    ball.Draw();
}


