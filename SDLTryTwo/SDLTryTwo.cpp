/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Game.h"
#include "Image.h"
Game *game = new Game(_strdup("Not mario"));

int main(int argc, char* args[])
{
	int status = 0;

	status += game->InitSDL();
	status += game->InitWindow(800, 600);
	status += game->InitText();
	if (status != 0)
	{
		printf("Error with code " + status);
	}

	status += game->Start();

	std::cout << "Loaded with status: " << status << std::endl;

	game->Update();


	delete game;
	//Quit SDL subsystems
	SDL_Quit();


	return 0;
}