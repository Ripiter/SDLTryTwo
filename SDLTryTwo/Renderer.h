#pragma once
#include <SDL.h>
#include "Animation.h"
class Renderer
{
public:
	SDL_Renderer* sdl_Renderer = NULL;

	void RenderImage(Image* img, int x, int y);
	void RenderImage(Image* img, int x, int y, int w, int h);
	void RenderImage(Image* img, int x, int y, SDL_Rect* clip);
	void RenderImage(Image* img, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);


	void RenderCustomEntity(RenderEntity* _entity);
	void RenderAnimation(Animation* _animation);

	void DrawFillSquare(SDL_Rect* transform, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void DrawRectSquare(SDL_Rect* transform, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void SetBackGroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};

