#pragma once
#include "Window.h"

class Game
{
private:
	bool quit = false;
	int InitPng();
public:
	Window* window;
	Image* backGroundImg;
	Image* playerImg;
	char* title;
	Game(char* _title);
	~Game();

	int InitWindow();
	int InitWindow(int _width, int _height);
	int InitSDL();
	int InitRenderer();
	int Start();
	void Update();
};

