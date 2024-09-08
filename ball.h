#pragma once
#include <raylib.h>
#include <paddle.h>

class Ball
{
public:
	Ball(int posx, int posy, float r, Color c, int sx, int sy, int sH, int sW);
	void Draw();
	void ChangeColor(Color c);
	void Update();
	bool PointInBall(int x, int y);
	int posX;
	int posY;
	float radius;
	Color color;
	int speed_x;
	int speed_y;
	int sHeight;
	int sWidth;
	void CollDetect(Paddle player);
};

