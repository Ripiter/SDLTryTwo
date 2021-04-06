#pragma once
#include <SDL.h>
#include <iostream>
class Entity
{
public:
	SDL_Rect* position;
	char* entityName;
	Entity();
	Entity(char* _entityName ,SDL_Rect* _position);
	virtual void Update() = 0;
};

