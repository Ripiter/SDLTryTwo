#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Text.h"

class Image
{
protected:
	int width, height;
	SDL_Renderer* renderer;

public:
	SDL_Texture* sdl_ImageTexture;
	SDL_Texture* LoadTexture(const char* _path);

	Image(SDL_Renderer* renderer);
	~Image();

	int GetWidth();
	int GetHeight();
	void FreeTexture();
	virtual void SetColor(Uint8 red, Uint8 green, Uint8 blue);
	void SetAlpha(int alpha);
	void SetBlendMode(SDL_BlendMode blendMode);
};
