#include "ball.h"
#include <math.h>

Ball::Ball(int posx, int posy, float r, Color c, int sx, int sy, int sH, int sW)
{
	posX = posx;
	posY = posy;
	radius = r;
	color = c;
	speed_x = sx;
	speed_y = sy;
	sHeight = sH;
	sWidth = sW;
}

void Ball::Draw()
{
	DrawCircle(posX, posY, radius, color);
}

void Ball::ChangeColor(Color c)
{
	color = c;
}
void Ball::Update() {
	posX += speed_x;
	posY += speed_y;
	if (posX >= sWidth - int(radius)) {// check right bound 
		posX = sWidth - int(radius);// move to edge
		speed_x = -speed_x;// -1 * to speed
	}
	if (posX <= 0) {// check left bound
		posX = int(radius);// move to edge
		speed_x = -speed_x;// -1 * to speed
	}
	if (posY >= sHeight - int(radius)) {// check if lower bound
		posY = sHeight - int(radius);// move to edge
		speed_y = -speed_y;// -1 * to speed
	}
	if (posY <= 0) {// check if upper bound
		posY = int(radius);// move to edge
		speed_y = -speed_y;// -1 * to speed
	}
}

bool Ball::PointInBall(int x, int y)
{
	if (abs(x - posX) ^ 2 + abs(y - posY) ^ 2 < radius ^ 2) return true;
	return false;
}


