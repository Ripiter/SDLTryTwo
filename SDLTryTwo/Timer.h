#pragma once
#include <SDL.h>
class Timer
{
	int elapsedTime = 0;
public:
	void Update();
	int GetElapsedTime();
	void Reset();
};

