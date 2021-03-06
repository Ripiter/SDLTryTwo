#include "Image.h"


Image::Image(SDL_Renderer* _renderer)
{
	renderer = _renderer;
}


Image::~Image()
{
	FreeTexture();
	IMG_Quit();
}
/*
int Image::LoadImage(const char* _path)
{
	FreeTexture();
	//Load splash image
	sdl_ImageTexture = LoadTexture(_path, _renderer);
	if (sdl_ImageTexture == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", _path, SDL_GetError());
		return -2;
	}
	printf("image created from path %s", _path);

	return 0;
}*/

int Image::GetWidth()
{
	return width;
}

int Image::GetHeight()
{
	return height;
}

void Image::FreeTexture()
{
	if (sdl_ImageTexture != NULL) {
		SDL_DestroyTexture(sdl_ImageTexture);
		sdl_ImageTexture = NULL;
		width = 0;
		height = 0;
	}
}

void Image::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(sdl_ImageTexture, red, green, blue);
}

void Image::SetAlpha(int alpha)
{
	SDL_SetTextureAlphaMod(sdl_ImageTexture, alpha);
}

void Image::SetBlendMode(SDL_BlendMode blendMode)
{
	//Set blending function
	SDL_SetTextureBlendMode(sdl_ImageTexture, blendMode);
}


SDL_Texture* Image::LoadTexture(const char* _path)
{
	FreeTexture();
	
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(_path);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", _path, SDL_GetError());
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		//Convert surface to screen format
		sdl_ImageTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (sdl_ImageTexture == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", _path, SDL_GetError());
		}
		width = loadedSurface->w;
		height = loadedSurface->h;

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return sdl_ImageTexture;
}



