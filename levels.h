#pragma once
#include <brick.h>


class Levels
{
public:
	Levels();//Ctor
	std::vector<Brick> levels[3];// a vector of vectors of bricks - each vectors of bricks is a level.
	bool CheckLevel(int i);//Check if level i is cleared (all bricks destroyed) - return true if so and false otherwise
	std::vector<Brick> GetLevels(int level);// function to get level at index level from levels array of vectors
private:
	std::vector<Brick> BuildSquare(int numRows, int numCols, int startx, int starty, int brickWidth, int brickHeight, int hp);// helper function to build a Square of bricks with parametars
};

