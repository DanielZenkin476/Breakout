#include "brick.h"

Brick::Brick(int x, int y, int w, int h, int hp)
{
	posX = x;
	posY = y;
	width = w;
	height = h;
	health = hp;
	colors = GetCellcolors();// max 12 colors- 12 health per brick at max 
	destroyed = false;
}

void Brick::Draw()
{
	if (destroyed == false) {// if health is 0 - brick is destroyed
		DrawRectangle(posX, posY, width, height, colors[health]);
	}
	else DrawRectangle(posX, posY, width, height, BLACK);
}
void Brick::Hit() {
	if (destroyed == false) {
		health = health - 1;
		if (health == 0) {
			destroyed = true;
		}
	}
}

