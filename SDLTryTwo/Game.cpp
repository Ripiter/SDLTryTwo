#include "Game.h"
Game::Game(char* _title)
{
	window = NULL;
	title = _title;
}

Game::~Game()
{
	delete backGroundImg;

	delete window;
}

int Game::InitWindow()
{
	if (window == NULL)
		window = new Window();
	int status = 0;
	//Create window
	window->SetSdlWindow(SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window->width, window->height, SDL_WINDOW_SHOWN));
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		status += -1;
	}
	else
	{
		status += InitRenderer();

		status += InitPng();
		//Update the surface
		window->UpdateWindow();
	}
	return status;
}

int Game::InitWindow(int _width, int _height)
{
	if (window == NULL)
		window = new Window(_width, _height);
	
	return InitWindow();
}


int Game::InitSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return -2;
	}

	return 0;
}

int Game::InitRenderer()
{
	if (window->renderer == NULL)
		window->renderer = new Renderer();

	window->renderer->sdl_Renderer = SDL_CreateRenderer(window->sdl_Window, -1, SDL_RENDERER_ACCELERATED);
	if (window->renderer->sdl_Renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return -1;
	}
	SDL_SetRenderDrawColor(window->renderer->sdl_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	return 0;
}

int Game::InitPng()
{
	int imgFlags = IMG_INIT_PNG;

	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return -1;
	}

	return 0;
}

int Game::Start()
{
	window->FillWindow(NULL, SDL_MapRGB(window->sdl_ScreenSurface->format, 0xFF, 0xFF, 0xFF));
	window->UpdateWindow();


	backGroundImg = new Image("../Img/Wall.png", window->renderer->sdl_Renderer);
	playerImg = new Image("../Img/PersonWithSaber.bmp", window->renderer->sdl_Renderer);


	window->renderer->SetBackGroundColor(0, 0, 0, 1);
	
	return 0;
}

void Game::Update()
{
	SDL_Event e;
	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			// user pressed button
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_w)
					printf("Pressed w");
				if (e.key.keysym.sym == SDLK_s)
					printf("Pressed s");
				if (e.key.keysym.sym == SDLK_a)
					printf("Pressed a");
				if (e.key.keysym.sym == SDLK_d)
					printf("Pressed d");
				if (e.key.keysym.sym == SDLK_ESCAPE) {
					printf("Pressed escape");
					quit = true;
				}
			}
		}

		window->ClearScreen();
		window->renderer->RenderImage(backGroundImg, 0, 0, window->width, window->height);

		window->renderer->RenderImage(playerImg, window->width / 2, window->height / 2, playerImg->GetWidth() / 2, playerImg->GetHeight() / 2);

		window->UpdateWindow();


	}
}
