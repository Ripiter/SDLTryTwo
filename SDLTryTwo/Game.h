#pragma once
#include "Button.h"
#include "Window.h"
#include "Animation.h"
#include "Player.h"
#include "Input.h"
#include "TextImage.h"
class Game
{
private:
	bool quit = false;
	int InitPng();
public:
	Window* window;
	Image* backGroundImg;
	Player* player;
	TextImage* imageTxt;
	Button* btn;
	const char* title;
	Game(const char* _title);
	~Game();

	int InitWindow();
	int InitWindow(int _width, int _height);
	int InitSDL();
	int InitRenderer();
	int InitText();
	int Start();
	void Update();
};

