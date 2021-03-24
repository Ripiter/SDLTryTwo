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

	Image(const char* _path, SDL_Renderer* renderer);
	~Image();

	int LoadImage(const char* _path, SDL_Renderer* screenSurface);
	int GetWidth();
	int GetHeight();
	void FreeTexture();
	void SetColor(int red, int green, int blue);
	void SetAlpha(int alpha);
	void SetBlendMode(SDL_BlendMode blendMode);
};
