#include "Renderer.h"


void Renderer::RenderImage(Image* img, int x, int y)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, img->GetWidth(), img->GetHeight() };
	SDL_RenderCopy(sdl_Renderer, img->sdl_ImageTexture, NULL, &renderQuad);
}
void Renderer::RenderImage(Image* img, int x, int y, int w, int h)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, w, h };
	SDL_RenderCopy(sdl_Renderer, img->sdl_ImageTexture, NULL, &renderQuad);
}

void Renderer::RenderImage(Image* img, int x, int y, SDL_Rect* clip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, img->GetWidth(), img->GetHeight()};

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy(sdl_Renderer, img->sdl_ImageTexture, clip, &renderQuad);
}



void Renderer::RenderCustomEntity(RenderEntity* _entity)
{
	SDL_RenderCopy(sdl_Renderer, _entity->entityImg->sdl_ImageTexture, NULL, _entity->position);
}

void Renderer::RenderAnimation(Animation* animation)
{
	RenderImage(animation->animationSheet, animation->currentEnitity->position->x, animation->currentEnitity->position->y, &animation->currectRect);
}



void Renderer::DrawFillSquare(SDL_Rect* transform, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(sdl_Renderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderFillRect(sdl_Renderer, transform);
}

void Renderer::DrawRectSquare(SDL_Rect* transform, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(sdl_Renderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderDrawRect(sdl_Renderer, transform);
}

void Renderer::SetBackGroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(sdl_Renderer, r, g, b, a);
}
