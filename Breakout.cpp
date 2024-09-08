// Breackout.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <raylib.h>
#include <colors.h>
#include <ball.h>
#include <paddle.h>
#include <brick.h>
#include <vector>

using namespace std;

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

int main()
{

    int brickWidth = 45;
    int brickHeight = 20;

    const int sWidth = 1000;
    const int sHeight = 800;
    InitWindow(sWidth, sHeight, "BreakDown");// size of window
    SetTargetFPS(60);// sets Game Target FPS

    // font 
    Font font = LoadFontEx("Font/hpsimplifiedjpan-regular.ttf", 64, 0, 0);// font for display
    //objects:

    Ball ball = Ball(sWidth / 2, sHeight - 150, 15, white, 7, -7, sHeight, sWidth);
    Paddle player = Paddle(sWidth / 2 - 50, sHeight - 60, 30, 100, sWidth, sHeight, WHITE);
    double interval = 0.2;
    // create bricks vector
    std::vector<Brick> bricks;
    int numRows = 5;     // Example number of rows
    int numCols = 20;    // Example number of bricks per row

    for (int a = 0; a < numRows * numCols; a++) {
        int posX = (a % numCols) * (brickWidth + 5); // Number of bricks per row
        int posY = (a / numCols) * (brickHeight + 5); // Move down after each row
        Brick br = Brick(posX, posY, brickWidth, brickHeight, 3);
        bricks.emplace_back(br);
    }



    while (WindowShouldClose() == false)// will run until esc key is pressed
    {
        BeginDrawing();//creates blank canvas so we can draw
        ClearBackground(BLACK);// change backround color, also to to a "soft reset" of screen to not show past iterations
 
        // movement 
        ball.Update();
        player.Update();

        // coll detection with player
        ball.CollDetect(player);

        // coll detection with brick
        for (int i = 0; i < 100; i++) {
            if (ball.CollDetectBrick(bricks[i])) {
                player.score += bricks[i].Hit();
            }
            bricks[i].Draw();// draw the brick after collision check and score update
        }

        // draw score:
        DrawTextEx(font, "Score", { 50,700 }, 38, 2, WHITE);// draw Score
        // drawing the score
        char scoreText[10];
        sprintf_s(scoreText, "%d", player.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, { 100 + (170 - textSize.x) / 2,700 }, 38, 2, WHITE);//draw score centered


        // draw player and ball 
        player.Draw();
        ball.Draw();

        EndDrawing();// end canvas drawing

    }
}

