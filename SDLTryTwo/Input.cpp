#include "Input.h"

std::vector<Button*> Input::buttons = {};

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
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			int x, y;
			SDL_GetMouseState(&x, &y);
			MouseButtonPressed(x, y);
		}
	}
}

void Input::MouseButtonPressed(int x, int y)
{
	for (int i = 0; i < buttons.size(); i++)
	{
		buttons.at(i)->ButtonEvent(x, y);
	}
}

void Input::AddButton(Button* btn)
{
	buttons.push_back(btn);
}
