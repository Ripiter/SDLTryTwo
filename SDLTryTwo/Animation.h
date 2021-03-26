#pragma once
#include <vector>
#include "RenderEntity.h"
class Animation
{
public:
	std::vector<SDL_Rect>* imagesTransform = new std::vector<SDL_Rect>;
	Image* animationSheet = nullptr;
	SDL_Rect currectRect;
	RenderEntity* currentEnitity = nullptr;
	int frames;
	Animation(RenderEntity* _rEntity, Image* _animationSheet, int _frames, int x);
	~Animation();

	void Update();
private:
	int currectFrame = 0;
	void UpdateFrame();
};

