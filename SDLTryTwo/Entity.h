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
	Entity(char* _entityName , float x, float y);
	virtual void Update() = 0;
	SDL_Rect* SetPosition(float x, float y);
};

