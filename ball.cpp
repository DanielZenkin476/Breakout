#include "ball.h"
#include <math.h>


Ball::Ball() {//Ctor - 0 to all values, ball is black ( invisible)
	posX = 0;
	posY = 0;
	radius = 0;
	color = WHITE;
	speed_x = 0;
	speed_y = 5;
	sHeight = 0;
	sWidth = 0;
}

Ball::Ball(int posx, int posy, float r, Color c, int sx, int sy, int sH, int sW)// Ctor of ball from parameters
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

void Ball::Draw()// draws ball on screen
{
	DrawCircle(posX, posY, radius, color);
}

void Ball::ChangeColor(Color c)// changes color of ball
{
	color = c;
}
bool Ball::Update() {// updates position of ball, checks for collision with screen limits. if hit bottom of screen return true(gameover) otherwise return false
	// update position
	posX += speed_x;
	posY += speed_y;
	//check for screen collision
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
		return true;// game over - return true
	}
	if (posY <= 0) {// check if upper bound
		posY = int(radius);// move to edge
		speed_y = -speed_y;// -1 * to speed
	}
	return false;
}

bool Ball::PointInBall(int x, int y)// checks if point x,y is in ball, returns true if so
{
	if ((x - posX) * (x - posX) + (y - posY) * (y - posY) < radius * radius) {// check by pitagoras function
		return true;
	}
	return false;
}

bool Ball::CollDetect(Paddle player)// detects collision with paddle player, changes speed and position accordingly
{
	for (int y = player.posY; y < player.posY + player.height; y++) {// check left and right side of paddle
		if (PointInBall(player.posX, y)) {// check left bound 
			posX = posX - (int)radius;// move to edge
			speed_x = -speed_x;// reverse speed
			return true;
			break;
		}
		if (PointInBall(player.posX + player.width, y)) {// check right bound 
			posX = player.posX + player.width + (int)radius;// move to edge
			speed_x = -speed_x;// reverse speed
			return true;
			break;
		}
	}

	for (int x = player.posX; x < player.posX + player.width; x++) {// check lower and upper bound of paddle
		if (PointInBall(x, player.posY)) {// check upper bound 
			posY = player.posY - (int)radius;// move to edge
			speed_y = -speed_y;// reverse speed
			return true;
			break;
		}
		if (PointInBall(x, player.posY + player.height)) {// check lower bound 
			posY = player.posY + player.height + (int)radius;// move to edge
			speed_y = -speed_y;// reverse speed
			return true;
			break;
		}
	}
	return false;
}

bool Ball::CollDetectBrick(Brick brick)// detects collision with Brick brick, changes speed and position accordingly, returns true if hit the brick
{
	bool hit = false;
	if (brick.destroyed == false) {
		for (int y = brick.posY; y < brick.posY + brick.height; y++) {// check left and right side of brick
			if (PointInBall(brick.posX, y)) {// check left bound 
				posX = posX - (int)radius;// move to edge
				speed_x = -speed_x;// reverse speed
				hit = true;
				break;
			}
			if (PointInBall(brick.posX + brick.width, y)) {// check right bound 
				posX = brick.posX + brick.width + (int)radius;// move to edge
				speed_x = -speed_x;// reverse speed
				hit = true;
				break;
			}
		}

		for (int x = brick.posX; x < brick.posX + brick.width; x++) {// check lower and upper bound of brick
			if (PointInBall(x, brick.posY)) {// check upper bound 
				posY = brick.posY - (int)radius;// move to edge
				speed_y = -speed_y;// reverse speed
				hit = true;
				break;
			}
			if (PointInBall(x, brick.posY + brick.height)) {// check lower bound 
				posY = brick.posY + brick.height + (int)radius;// move to edge
				speed_y = -speed_y;// reverse speed
				hit = true;
				break;
			}
		}
	}
	return hit;
}



