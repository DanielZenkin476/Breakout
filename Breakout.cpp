// Breackout.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <raylib.h>
#include <game.h> 

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
    // create game
    Game game = Game(sHeight, sWidth, font);


    while (WindowShouldClose() == false)// will run until esc key is pressed
    {
        BeginDrawing();//creates blank canvas so we can draw
        ClearBackground(BLACK);// change backround color, also to to a "soft reset" of screen to not show past iterations
 
        // movement 
        game.Update();

        // coll detection with player
        game.CollDetect();

        // draw score:
        game.Draw();

        EndDrawing();// end canvas drawing

    }
}

