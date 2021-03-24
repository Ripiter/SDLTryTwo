#include "Game.h"
Game::Game(char* _title)
{
	window = NULL;
	title = _title;
}

Game::~Game()
{
	delete backGroundImg;
	delete playerImg;


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

	window->renderer->sdl_Renderer = SDL_CreateRenderer(window->sdl_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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

	/*
	backGroundImg = new Image("../Img/Wall.png", window->renderer->sdl_Renderer);

	// we tell sdl that our back ground can become transparent
	backGroundImg->SetBlendMode(SDL_BLENDMODE_BLEND);
	*/

	playerImg = new Image("../img/foo.png", window->renderer->sdl_Renderer);

	playerAnimation = new Animation(playerImg, 4, 64);

	window->renderer->SetBackGroundColor(255, 0, 0, 1);
	
	return 0;
}

void Game::Update()
{
	SDL_Event e;

	int frame = 0;
	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			// user pressed button
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_ESCAPE) {
					printf("Pressed escape");
					quit = true;
				}
			}
		window->ClearScreen();

		SDL_Rect* currentClip = &playerAnimation->imagesTransform->at(frame / 4);
		window->renderer->RenderImage(playerImg, (window->width - currentClip->w) / 2, (window->height - currentClip->h) / 2, currentClip);

		window->UpdateWindow();

		++frame;

		//Cycle animation
		if (frame / 4 >= playerAnimation->frames)
		{
			frame = 0;
		}
	}
}
