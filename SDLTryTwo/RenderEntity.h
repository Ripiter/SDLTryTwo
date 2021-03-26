#pragma once
#include "Entity.h"
#include "Image.h"
class RenderEntity : public Entity 
{
public:
	Image* entityImg = nullptr;
	RenderEntity();
	RenderEntity(char* _entityName, Image* _entityImg, SDL_Rect* _entityPosition);
	~RenderEntity();

};

