#include "Renderer.h"


void Renderer::RenderSdlImage(Image* img, int x, int y)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, img->GetWidth(), img->GetHeight() };
	SDL_RenderCopy(sdl_Renderer, img->sdl_ImageTexture, NULL, &renderQuad);
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
