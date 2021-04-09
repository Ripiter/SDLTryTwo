#include "Timer.h"

int Timer::GetElapsedTime()
{
	return SDL_GetTicks() - elapsedTime;
}

void Timer::Reset()
{
	elapsedTime = SDL_GetTicks();
}
