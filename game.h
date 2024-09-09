#pragma once
#include <paddle.h>
#include <brick.h>
#include <ball.h>
#include <raylib.h>

class Game
{
public:
	Game(int sH, int sW, Font f);
	Ball ball;
	Paddle player;
	std::vector<Brick> bricks;
	void Init();
	void Update();
	void CollDetect();
	void Draw();
	int sHeight;
	int sWidth;
	Font font;
};

