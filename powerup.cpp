#include "powerup.h"
#include <iostream>
using namespace std;

Powerup::Powerup(int posx, int posy, float r, int sH, int sW, int i ) {
	posX = posx;
	posY = posy;
	radius = r;
	color = GetCellcolors()[i];
	speed_x = 0;
	speed_y = 10;
	sHeight = sH;
	sWidth = sW;
	index = i;
}

bool Powerup::UpdatePower()
{
	posY = posY + speed_y;
	if (posY >= sHeight - int(radius)) {
		return true;
	}
	return false;
}


