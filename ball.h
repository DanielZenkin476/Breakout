#pragma once
#include <raylib.h>
#include <paddle.h>
#include <brick.h>

class Ball
{
public:
	Ball();// defualt Ctor
	Ball(int posx, int posy, float r, Color c, int sx, int sy, int sH, int sW);//Ctor
	void Draw();//Draws ball
	void ChangeColor(Color c);// changes color of ball
	bool Update();// updates position of ball based on current speed values
	bool PointInBall(int x, int y);// check if point x,y is in radius of ball
	int posX;//posX of center of ball
	int posY;//posY of center of ball
	float radius;//radius of ball
	Color color;//ball color
	int speed_x;// speed x axis
	int speed_y;//speed y axis
	int sHeight;// screen height
	int sWidth;// screen width
	void CollDetect(Paddle player);// coll detection with paddle
	bool CollDetectBrick(Brick brick);// coll detection with brick
};

