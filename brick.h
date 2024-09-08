#pragma once
// class for each brick on playing field . 
#include <colors.h>
#include<vector>

class Brick
{
public:
	Brick(int x, int y, int w, int h, int hp);
	int posX, posY, width, height;
	void Draw();
	bool destroyed;
	void Hit();
private:
	std::vector<Color> colors;
	int health;
};

