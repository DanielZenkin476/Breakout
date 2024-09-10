#pragma once
#include <raylib.h>
class Paddle
{
public:
	Paddle();//Defualt Ctor
	Paddle(int posx, int posy, int h, int w, int sW, int sH, Color c);//Ctor by paramaters
	void Draw();// draw padle
	void MoveLeft();// move paddle left
	void MoveRight();// move paddle right
	int posX;// pos x of paddle
	int posY;// pos y of paddle
	int height;// height of paddle
	int width;// width of paddle
	Color color;// color of paddle
	int sHeight;//screen height
	int sWidth;//screen width
	int speed;// speed of paddle 
	void Doublewidth();
};

