#pragma once
#include <vector>
#include "RenderEntity.h"
class Animation
{
public:
	// All the cuts of the spread sheet
	std::vector<SDL_Rect>* imagesTransform = new std::vector<SDL_Rect>;

	// Spread sheet
	Image* animationSheet = nullptr;

	// Currect transform width and height that are being shown from the spread sheet 
	SDL_Rect currectRect;

	// Current entity that is getting animated
	RenderEntity* currentEnitity = nullptr;
	int frames;

	/// <param name="_rEntity">Entity that the animation is for</param>
	/// <param name="_animationSheet">The big image that is going to get cut</param>
	/// <param name="_frames">Amount of frames in the animation spread sheet</param>
	/// <param name="x">Cut animation sheet every x amount</param>
	Animation(RenderEntity* _rEntity, Image* _animationSheet, int _frames, int x);
	~Animation();

	/// <summary>
	/// Update rect that cuts the image
	/// </summary>
	void Update();
private:
	int currectFrame = 0;
	void UpdateFrame();
};

