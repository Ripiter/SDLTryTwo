#include "Player.h"


Player::Player(char* _entityName, Image* _img, SDL_Rect* _position) : RenderEntity::RenderEntity(_entityName, _img, _position)
{

}

Player::~Player()
{
	delete playerAnimation;
}
