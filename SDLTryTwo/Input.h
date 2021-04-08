#pragma once
#include <SDL.h>
#include <vector>
#include "Button.h"
enum class InputKey {
	w = SDLK_w,
	a = SDLK_a,
	s = SDLK_s,
	d = SDLK_d,
	q = SDLK_q,
	e = SDLK_e,
	space = SDLK_SPACE,
	escape = SDLK_ESCAPE
};

class Input
{
private:
	static int keyPressed;
public:
	static std::vector<Button*> buttons;
	//std::vector<IHover*> hovering;

	Input();
	static bool GetButtonDown(InputKey key);
	static void UpdateKey();
	static void MouseButtonPressed(int x, int y);
	static void AddButton(Button* btn);
};

