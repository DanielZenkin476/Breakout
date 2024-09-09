#pragma once
#include <paddle.h>
#include <levels.h>
#include <ball.h>
#include <raylib.h>

class Game
{
public:
	Game(int sH, int sW, Font f);
	Ball ball;
	Paddle player;
	Levels levels;
	void Init();
	void Update();
	void CollDetect();
	void CheckLevelclear();
	void Draw();
	void HandleInput();
	int sHeight;
	int sWidth;
	Font font;
	int level;
	bool gameover;
private:
	int score;
};

