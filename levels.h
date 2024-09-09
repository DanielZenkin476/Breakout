#pragma once
#include <brick.h>


class Levels
{
public:
	Levels();
	std::vector<std::vector<Brick>> levels;// a vector of vectors of bricks - each vectors of bricks is a level.
};

