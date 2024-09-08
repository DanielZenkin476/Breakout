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

void CollisionDetect(Paddle player, Ball ball) {
    for (int x = player.posX; x < player.posX + player.width; x++) {// check lower and upper bound of paddle
        if (ball.PointInBall(x, player.posY)) {// check upper bound 
            ball.posY = player.posY - (int)ball.radius;// move to edge
            ball.speed_y = -ball.speed_y;
            break;
        }
        if (ball.PointInBall(x, player.posY + player.height)) {// check lower bound 
            ball.posY = player.posY + player.height + (int)ball.radius;// move to edge
            ball.speed_y = -ball.speed_y;
            break;
        }
    }
    for (int y = player.posY; y < player.posY + player.height; y++) {// check left and right side of paddle
        if (ball.PointInBall(player.posX, y)) {// check upper bound 
            ball.posX = player.posX - (int)ball.radius;// move to edge
            ball.speed_x = -ball.speed_x;
            break;
        }
        if (ball.PointInBall(player.posX+ player.width, y)) {// check lower bound 
            ball.posX = player.posX + player.width + (int)ball.radius;// move to edge
            ball.speed_x = -ball.speed_x;
            break;
        }
    }
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
        // collision check here - doesnt work as a standalone function , neet to check

        for (int y = player.posY; y < player.posY + player.height; y++) {// check left and right side of paddle
            if (ball.PointInBall(player.posX, y)) {// check left bound 
                ball.posX = player.posX - (int)ball.radius;// move to edge
                ball.speed_x = -ball.speed_x;
                break;
            }
            if (ball.PointInBall(player.posX + player.width, y)) {// check right bound 
                ball.posX = player.posX + player.width + (int)ball.radius;// move to edge
                ball.speed_x = -ball.speed_x;
                break;
            }
        }

        for (int x = player.posX; x < player.posX + player.width; x++) {// check lower and upper bound of paddle
            if (ball.PointInBall(x, player.posY)) {// check upper bound 
                ball.posY = player.posY - (int)ball.radius;// move to edge
                ball.speed_y = -ball.speed_y;
                break;
            }
            if (ball.PointInBall(x, player.posY + player.height)) {// check lower bound 
                ball.posY = player.posY + player.height + (int)ball.radius;// move to edge
                ball.speed_y = -ball.speed_y;
                break;
            }
        }


        player.Draw();
        ball.Draw();

        EndDrawing();// end canvas drawing

    }
}

