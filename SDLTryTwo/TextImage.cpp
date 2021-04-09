#include "TextImage.h"
TextImage::TextImage(Text* _text, SDL_Renderer* renderer) : Image::Image(renderer)
{
	text = _text;
	ReloadTexture();
}
TextImage::~TextImage()
{
	delete text;
}
void TextImage::ReloadTexture()
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
		sdl_ImageTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
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
		textSurface = NULL;
	}
}

void TextImage::SetText(std::string _text)
{
	if (text->text == _text)
		return;

	text->text = _text;
	ReloadTexture();
}

void TextImage::SetColor(Uint8 r, Uint8 g, Uint8 b)
{
	if (text->color.r == r && text->color.g == g && text->color.b == b)
		return;

	text->color = { r, g, b };
	ReloadTexture();
}
