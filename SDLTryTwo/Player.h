#pragma once
#include "Animation.h"
#include "RenderEntity.h"
#include "Input.h"
class Player : public RenderEntity
{
public:
	Animation* playerAnimation = nullptr;
	
	Player(char* _entityName, Image* _img, SDL_Rect* _position);
	Player(char* _entityName, Image* _img, float _x, float _y);
	~Player();

	virtual void Update();
	void UpdatePlayerMovement();
};

