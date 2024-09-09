#pragma once
#include <brick.h>


class Levels
{
public:
	Levels();
	std::vector<Brick> levels[3];// a vector of vectors of bricks - each vectors of bricks is a level.
	bool clears[3];
	bool CheckLevel(int i);
	std::vector<Brick> GetLevels(int level);
	std::vector<Brick> BuildSquare(int numRows, int numCols, int startx, int starty, int brickWidth, int brickHeight, int hp);
};

