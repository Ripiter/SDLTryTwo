#include "Entity.h"

Entity::Entity()
{
	entityName = _strdup("Deafult");
	position = NULL;
}

Entity::Entity(char* _entityName, SDL_Rect* _position)
{
	entityName = _entityName;
	position = _position;
}

Entity::Entity(char* _entityName, float x, float y)
{
	entityName = _entityName;
	SetPosition(x, y);
}

SDL_Rect* Entity::SetPosition(float x, float y)
{
	if (!position) {
		position = new SDL_Rect();
	}
	position->x = x;
	position->y = y;

	return position;
}
