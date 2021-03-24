#pragma once
#include <iostream>
#include <SDL.h>

#include <SDL_image.h>

class Image
{
private:
	SDL_Texture* LoadTexture(const char* _path, SDL_Renderer* screenSurface);
	int width, height;
public:
	SDL_Texture* sdl_ImageTexture;

	Image(const char* _path, SDL_Renderer* screenSurface);
	~Image();

	int LoadImage(const char* _path, SDL_Renderer* screenSurface);
	int GetWidth();
	int GetHeight();
	void FreeTexture();
};
