#pragma once
// class for each brick on playing field . 
#include <colors.h>
#include<vector>

class Brick
{
public:
	Brick(int x, int y, int w, int h, int hp);//Ctor
	int posX, posY, width, height;// position and width/height of brick
	void Draw();// function draws brick onscreen
	bool destroyed;// to see if brick is destroyed (hp==0)
	int Hit();//function to be invoked when brick is hit - reduces hp by one, if brick destroyed - returns destScore, otherwise returns 0
private:
	std::vector<Color> colors;// colors to use in diffrent hp values
	int health;// health of brick
	int destScore; // score to be added upon destruction
};

