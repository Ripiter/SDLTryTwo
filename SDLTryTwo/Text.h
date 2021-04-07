#pragma once
#include <string>
#include <SDL_ttf.h>
#include <SDL.h>
class Text
{
public:
	std::string text;
	SDL_Color color;
	TTF_Font* font = NULL;
	Text(std::string _text, SDL_Color _color, TTF_Font* _font = NULL);
	~Text();
};

