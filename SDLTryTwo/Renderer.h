#pragma once
#include <SDL.h>
#include "Image.h"
class Renderer
{
public:

	SDL_Renderer* sdl_Renderer = NULL;

	void RenderSdlImage(Image* img, int x, int y);
	void DrawFillSquare(SDL_Rect* transform, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void DrawRectSquare(SDL_Rect* transform, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void SetBackGroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};

