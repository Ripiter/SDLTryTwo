#pragma once
#include <SDL.h>
#include <iostream>
#include "Image.h"
#include "Renderer.h"
class Window
{
public:
	//The window we'll be rendering to
	SDL_Window* sdl_Window = NULL;
	SDL_Surface* sdl_ScreenSurface = NULL;
	Renderer* renderer = NULL;

	int width, height;
	//Screen dimension constants
	const int DEFAULT_SCREEN_WIDTH = 640;
	const int DEFAULT_SCREEN_HEIGHT = 480;

	Window();
	Window(int _width, int _height);
	~Window();


	void ClearScreen();
	void SetSdlWindow(SDL_Window *sdlWindow);
	void FillWindow(SDL_Rect* rect, Uint32 color);
	void UpdateWindow();
};

