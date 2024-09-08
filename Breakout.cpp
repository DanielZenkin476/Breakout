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

    int brickWidth = 50;
    int brickHeight = 10;

    const int sWidth = 1200;
    const int sHeight = 800;
    InitWindow(sWidth, sHeight, "PONG");// size of window
    SetTargetFPS(60);// sets Game Target FPS

    // add font here - LoadFontEx
    Ball ball = Ball(sWidth / 2, sHeight - 150, 15, white, 3, -7, sHeight, sWidth);
    Paddle player = Paddle(sWidth / 2 - 50, sHeight - 60, 30, 100, sWidth, sHeight, WHITE);
    double interval = 0.2;
    // create bricks vector
    std::vector<Brick> bricks;
    for (int i = 0; i < 100; i++) {
        int posX = (i % 25) * (brickWidth + 5); // 25 bricks per row, adjust spacing
        int posY = (i / 25) * (brickHeight + 5); // Move down every 25 bricks
        bricks.emplace_back(posX, posY, brickWidth, brickHeight, 4);
    }



    while (WindowShouldClose() == false)// will run until esc key is pressed
    {
        BeginDrawing();//creates blank canvas so we can draw
        ClearBackground(BLACK);// change backround color, also to to a "soft reset" of screen to not show past iterations
        // moves
        ball.Update();
        player.Update();
        // coll detection with player
        ball.CollDetect(player);
        // coll detection with brick
        for (int i = 0; i < 100; i++) {
            if (ball.CollDetectBrick(bricks[i])) {
                bricks[i].Hit();
            }
            bricks[i].Draw();
        }
        player.Draw();
        ball.Draw();

        EndDrawing();// end canvas drawing

    }
}

