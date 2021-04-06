#include "Input.h"

bool Input::GetButtonDown(InputKey key)
{
	if (Input::keyPressed == (int)key) {
		Input::keyPressed = 0;
		return true;
	}

	return false;
}

int Input::keyPressed = 0;


void Input::UpdateKey()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		// user pressed button
		if (e.type == SDL_KEYDOWN)
		{
			Input::keyPressed = e.key.keysym.sym;
		}
	}
}
