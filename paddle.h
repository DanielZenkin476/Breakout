#pragma once
#include <raylib.h>
#include <ball.h>
class Paddle
{
public:
	Paddle(int posx, int posy, int h, int w, int sW, int sH, Color c);
	void Draw();
	void Update();
	int posX;
	int posY;
	int height;
	int width;
	Color color;
	int sHeight;
	int sWidth;
	int speed;
};

