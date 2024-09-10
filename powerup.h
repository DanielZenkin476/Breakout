#pragma once
#include "ball.h"
#include <paddle.h>
#include <colors.h>

class Powerup :virtual public Ball
{
public:
	Powerup(int posx, int posy, float r, int sH, int sW, int i);
	int index;
	bool UpdatePower();
};

