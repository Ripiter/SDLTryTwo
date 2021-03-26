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
