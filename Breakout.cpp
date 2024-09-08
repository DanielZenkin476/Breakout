// Breackout.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <raylib.h>
#include <colors.h>
#include <ball.h>
#include <paddle.h>
#include <brick.h>

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
    const int sWidth = 1200;
    const int sHeight = 800;
    InitWindow(sWidth, sHeight, "PONG");// size of window
    SetTargetFPS(60);// sets Game Target FPS

    // add font here - LoadFontEx
    Ball ball = Ball(sWidth / 2, sHeight / 2, 15, white, 3, 3, sHeight, sWidth);
    Paddle player = Paddle(sWidth / 2 - 50, sHeight - 60, 30, 100, sWidth, sHeight, red);
    double interval = 0.2;

    while (WindowShouldClose() == false)// will run until esc key is pressed
    {
        BeginDrawing();//creates blank canvas so we can draw
        ClearBackground(BLACK);// change backround color, also to to a "soft reset" of screen to not show past iterations

        ball.Update();
        player.Update();
        ball.CollDetect(player);
        player.Draw();
        ball.Draw();

        EndDrawing();// end canvas drawing

    }
}

