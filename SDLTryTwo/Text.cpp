#include "Text.h"

Text::Text(std::string _text, SDL_Color _color, TTF_Font* _font)
{
	text = _text;
	color = _color;

    if (_font == NULL)
        font = TTF_OpenFont("../Fonts/lazy.ttf", 28);
    else
        font = _font;

    if(font == NULL)
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
}

Text::~Text()
{
    TTF_CloseFont(font);
    font = NULL;
}
