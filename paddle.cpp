#include "paddle.h"

Paddle::Paddle() {//defualt cctor - blac
	posX = 0;
	posY = 0;
	height = 0;
	width = 0;
	sWidth = 0;
	sHeight = 0;
	color = BLACK;
	speed = 0;
	
}


Paddle::Paddle(int posx, int posy, int h, int w, int sW, int sH, Color c) {// ctor by parametars
	posX = posx;
	posY = posy;
	height = h;
	width = w;
	sWidth = sW;
	sHeight = sH;
	color = c;
	speed = 10;
	
}
void Paddle::Draw() {// draws paddle onscreen
	DrawRectangle(posX, posY, width, height, color);
}

void Paddle::MoveLeft()// move paddle to left if possible
{
	if (posX <= 0) {
		posX = 0;
	}
	else posX = posX - speed;
}

void Paddle::MoveRight()// move paddle to right if possible
{
	if (posX >= sWidth - width) {
		posX = sWidth - width;
	}
	else posX = posX + speed;
}
	
	
