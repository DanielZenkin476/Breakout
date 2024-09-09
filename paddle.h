#pragma once
#include <raylib.h>
class Paddle
{
public:
	Paddle();
	Paddle(int posx, int posy, int h, int w, int sW, int sH, Color c);
	void Draw();
	void MoveLeft();
	void MoveRight();
	int posX;
	int posY;
	int height;
	int width;
	Color color;
	int sHeight;
	int sWidth;
	int speed;
};

