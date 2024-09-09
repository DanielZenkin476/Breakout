#include "game.h"

Game::Game(int sH, int sW, Font f) {
	sHeight = sH;
	sWidth = sW;
    font = f;
	ball = Ball(sWidth / 2, sHeight - 150, 15, WHITE, 7, -7, sHeight, sWidth);
	player = Paddle(sWidth / 2 - 50, sHeight - 60, 30, 100, sWidth, sHeight, WHITE);
    score = 0;
    // first level 
    int numRows = 5;     
    int numCols = 20;    
    int brickWidth = 45;
    int brickHeight = 20;
    for (int a = 0; a < numRows * numCols; a++) {
        int posX = (a % numCols) * (brickWidth + 5); 
        int posY = (a / numCols) * (brickHeight + 5); 
        Brick br = Brick(posX, posY, brickWidth, brickHeight, 3);
        bricks.emplace_back(br);
    }
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
        if (ball.CollDetectBrick(bricks[i])) {
            score += bricks[i].Hit();
        }
        bricks[i].Draw();// draw the brick after collision check and score update
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


