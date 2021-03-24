#pragma once
#include "Image.h"
#include <vector>
class Animation
{

public:
	std::vector<SDL_Rect>* imagesTransform = new std::vector<SDL_Rect>;

	int frames;
	Animation(Image* _imgTexture, int _frames, int x);
	~Animation();
};

