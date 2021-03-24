#include "Image.h"


Image::Image(const char* _path, SDL_Renderer* _renderer)
{
	sdl_ImageTexture = NULL;
	LoadImage(_path, _renderer);
}

Image::~Image()
{
	SDL_DestroyTexture(sdl_ImageTexture);
	sdl_ImageTexture = NULL;


	IMG_Quit();
}

int Image::LoadImage(const char* _path, SDL_Renderer* _renderer)
{
	//Load splash image
	sdl_ImageTexture = LoadTexture(_path, _renderer);
	if (sdl_ImageTexture == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", _path, SDL_GetError());
		return -2;
	}
	printf("image created from path %s", _path);

	return 0;
}


SDL_Texture* Image::LoadTexture(const char* _path, SDL_Renderer* _renderer)
{
	//The final optimized image
	SDL_Texture* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(_path);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", _path, SDL_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", _path, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}