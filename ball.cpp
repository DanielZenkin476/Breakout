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
	if ((x - posX) * (x - posX) + (y - posY) * (y - posY) < radius * radius) {
		return true;
	}
	return false;
}

void Ball::CollDetect(Paddle player)
{
	for (int y = player.posY; y < player.posY + player.height; y++) {// check left and right side of paddle
		if (PointInBall(player.posX, y)) {// check left bound 
			posX = posX - (int)radius;// move to edge
			speed_x = -speed_x;
			break;
		}
		if (PointInBall(player.posX + player.width, y)) {// check right bound 
			posX = player.posX + player.width + (int)radius;// move to edge
			speed_x = -speed_x;
			break;
		}
	}

	for (int x = player.posX; x < player.posX + player.width; x++) {// check lower and upper bound of paddle
		if (PointInBall(x, player.posY)) {// check upper bound 
			posY = player.posY - (int)radius;// move to edge
			speed_y = -speed_y;
			break;
		}
		if (PointInBall(x, player.posY + player.height)) {// check lower bound 
			posY = player.posY + player.height + (int)radius;// move to edge
			speed_y = -speed_y;
			break;
		}
	}
}



