// Breackout.cpp : This file contains the 'main' function. Program execution begins and ends there.
// this is a project made in C++ using microsoft visual studio 

#include <iostream>
#include <raylib.h>
#include <game.h> // main game class

using namespace std;//for easy output

int main()
{
    // screed res
    const int sWidth = 1000;
    const int sHeight = 800;
    // init window
    InitWindow(sWidth, sHeight, "BreakDown");// size of window
    SetTargetFPS(60);// sets Game Target FPS

    
    // font 
    Font font = LoadFontEx("Font/hpsimplifiedjpan-regular.ttf", 64, 0, 0);// font for display
    // create game
    Game game = Game(sHeight, sWidth, font);


    while (WindowShouldClose() == false)// will run until esc key is pressed, game loop
    {
        BeginDrawing();//creates blank canvas so we can draw
        ClearBackground(BLACK);// change backround color, also to to a "soft reset" of screen to not show past iterations

        game.CheckLevelclear();// to check if level is cleared before starting game loop
 
        // movement 
        game.Update();

        // coll detection ball with player and bricks 
        game.CollDetect();

        // draw score:
        game.Draw();

        EndDrawing();// end canvas drawing

    }
}

