#pragma once
#include <SDL.h>
#include "Image.h"
class Renderer
{
public:

	SDL_Renderer* sdl_Renderer = NULL;

	void RenderImage(Image* img, int x, int y);
	void RenderImage(Image* img, int x, int y, int w, int h);
	void DrawFillSquare(SDL_Rect* transform, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void DrawRectSquare(SDL_Rect* transform, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void SetBackGroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};

