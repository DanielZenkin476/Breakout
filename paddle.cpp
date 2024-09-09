#include "paddle.h"

Paddle::Paddle() {
	posX = 0;
	posY = 0;
	height = 0;
	width = 0;
	sWidth = 0;
	sHeight = 0;
	color = BLACK;
	speed = 0;
	score = 0;
}


Paddle::Paddle(int posx, int posy, int h, int w, int sW, int sH, Color c) {
	posX = posx;
	posY = posy;
	height = h;
	width = w;
	sWidth = sW;
	sHeight = sH;
	color = c;
	speed = 10;
	score = 0;
}
void Paddle::Draw() {
	DrawRectangle(posX, posY, width, height, color);
}
void Paddle::Update() {

	if (IsKeyDown(KEY_LEFT)) {
		if (posX <= 0) {
			posX = 0;
		}
		else posX = posX - speed;
	}
	if (IsKeyDown(KEY_RIGHT)) {
		if (posX >= sWidth - width) {
			posX = sWidth - width;
		}
		else posX = posX + speed;
	}
}
	
	
