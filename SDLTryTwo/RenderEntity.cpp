#include "RenderEntity.h"

RenderEntity::RenderEntity()
{
}

RenderEntity::RenderEntity(char* _entityName, Image* _entityImg, SDL_Rect* _entityPosition) : Entity::Entity(_entityName, _entityPosition)
{
	entityImg = _entityImg;
}

RenderEntity::RenderEntity(char* _entityName, Image* _entityImg, float _x, float _y) : Entity::Entity(_entityName, _x, _y)
{
	entityImg = _entityImg;
}

RenderEntity::~RenderEntity()
{
	delete entityImg;
}
