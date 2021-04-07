#include "Image.h"


Image::Image(const char* _path, SDL_Renderer* _renderer)
{
	LoadImage(_path, _renderer);
}

Image::Image(Text* _text, SDL_Renderer* renderer)
{
	LoadText(_text, renderer);
}

Image::~Image()
{
	FreeTexture();
	IMG_Quit();
}

int Image::LoadImage(const char* _path, SDL_Renderer* _renderer)
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
}

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

void Image::SetColor(int red, int green, int blue)
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
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		//Convert surface to screen format
		optimizedSurface = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", _path, SDL_GetError());
		}
		width = loadedSurface->w;
		height = loadedSurface->h;

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

SDL_Texture* Image::LoadText(Text* text, SDL_Renderer* _renderer)
{
	//Get rid of preexisting texture
	FreeTexture();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(text->font, text->text.c_str(), text->color);
	if (textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		//Create texture from surface pixels
		sdl_ImageTexture = SDL_CreateTextureFromSurface(_renderer, textSurface);
		if (sdl_ImageTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			width = textSurface->w;
			height = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}

	return sdl_ImageTexture;
}

