#pragma once
#include <paddle.h>//paddle class - player
#include <levels.h>// levels class 
#include <ball.h>// ball class
#include <raylib.h>
#include <powerup.h>
#include <iostream>
using namespace std;

class Game
{
public:
	Game(int sH, int sW, Font f);//Ctor
	Ball ball;// ball object- maybe switch to vector for multiple balls
	Paddle player;// player paddle 
	Levels levels;// levels of game
	void Init();// Init function- used to initilize a level (starts from begining)
	void Update();// update game state - updates ball position and handles input (calls upon handleinput and ball.update)
	void CollDetect();// detects collision of ball with paddle or bricks , also to save an extra loop Draws bricks as well!
	void CheckLevelclear();//checks if level is cleared- if so changes to next level and init.
	void Draw();// draws current game instance
	void HandleInput();// handle player input, 
	int sHeight;// screem height
	int sWidth;// screen width
	Font font;// font used in game for display
	int level;// saves current level (0-2)
	bool gameover;// false if not game over- true if game over (resets)
	std::vector<Brick> currLevel;// vector of bricks- current level in play
	std::vector <Powerup> powerups;// vector of powerups, starts empty
	void PowerUpdateDraw();
private:
	int score;// score
};

