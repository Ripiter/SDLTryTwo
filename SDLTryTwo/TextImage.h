#pragma once
#include "Image.h"
class TextImage : public Image
{

private:
	void ReloadTexture();

public:
	Text* text;

	TextImage(Text* _text, SDL_Renderer* renderer);
	~TextImage();
	SDL_Texture* LoadText(Text* text);
	void SetText(std::string _text);
	void SetText(std::string _text, SDL_Color color);
};

