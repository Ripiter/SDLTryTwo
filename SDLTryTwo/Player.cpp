#include "Player.h"


Player::Player(char* _entityName, Image* _img, SDL_Rect* _position) : RenderEntity::RenderEntity(_entityName, _img, _position)
{

}

Player::~Player()
{
	delete playerAnimation;
}

void Player::Update()
{
	UpdatePlayerMovement();
}

void Player::UpdatePlayerMovement()
{
	if (Input::GetButtonDown(InputKey::w)) {
		position->y -= 10;
	}
	else if (Input::GetButtonDown(InputKey::a)) {
		position->x -= 10;
	}
	else if (Input::GetButtonDown(InputKey::s)) {
		position->y += 10;
	}
	else if (Input::GetButtonDown(InputKey::d)) {
		position->x += 10;
	}
}
