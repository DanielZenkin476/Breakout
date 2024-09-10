#include "brick.h"

Brick::Brick(int x, int y, int w, int h, int hp)// Ctor by parametaes
{
	posX = x;
	posY = y;
	width = w;
	height = h;
	health = hp;
	colors = GetCellcolors();// max 12 colors- 12 health per brick at max 
	destroyed = false;
	destScore = hp * 20;// score calc.
}

void Brick::Draw()// Draws brick onscreen if brick isnt destroyed
{
	if (destroyed == false) DrawRectangle(posX, posY, width, height, colors[health]);
}
int Brick::Hit() {//function to be invoked when brick is hit - reduces hp by one, if brick destroyed - returns destScore, otherwise returns 0
	if (destroyed == false) {// if still in game
		health = health - 1;// reduce health
		if (health == 0) {// if hp ==0
			destroyed = true;// now destroyed
			return destScore;// returns score
		}
	}
	return 0;// returns 0
}

