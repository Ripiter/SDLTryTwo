#pragma once
#include "Animation.h"
#include "RenderEntity.h"
class Player : public RenderEntity
{
public:
	Animation* playerAnimation = nullptr;
	
	Player(char* _entityName, Image* _img, SDL_Rect* _position);
	~Player();
};

