#include "Game.h"
Game::Game(const char* _title)
{
	window = NULL;
	title = _title;
	player = nullptr;
	backGroundImg = nullptr;
}

Game::~Game()
{
	delete backGroundImg;
	delete player;
	delete window;
	delete txtImage;
	TTF_Quit();
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

int Game::InitText()
{
	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		return -3;
	}
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

	TextImage* buttonImg = new TextImage(new Text("Yaaa", {0,255,0}), window->renderer->sdl_Renderer);
;
	btn = new Button(_strdup("First button"), buttonImg, window->width / 2, window->height / 2);

	Input::AddButton(btn);

	txtImage = new TextImage(new Text("Time", { 0, 0, 0 }), window->renderer->sdl_Renderer);

	/*
	backGroundImg = new Image(window->renderer->sdl_Renderer);
	backGroundImg->LoadTexture("../Img/Wall.png");
	// we tell sdl that our back ground can become transparent
	backGroundImg->SetBlendMode(SDL_BLENDMODE_BLEND);
	*/

	Image* img = new Image(window->renderer->sdl_Renderer);
	img->LoadTexture("../img/foo.png");

	player = new Player(_strdup("Player"), img, window->width / 2, window->height / 2);
	player->playerAnimation = new Animation(player, player->entityImg, 4, 64);
	

	window->renderer->SetBackGroundColor(255, 0, 0, 1);



	return 0;
}

void Game::Update()
{
	Timer timer;
	while (!quit)
	{
		Input::UpdateKey();

		if (Input::GetButtonDown(InputKey::escape)) {
			printf("Pressed escape");
			quit = true;
		}

		if (Input::GetButtonDown(InputKey::e)) {
			//startTime = SDL_GetTicks();
			timer.Reset();
		}
		//timer.Update();

		//timeText.str("");
		//timeText << "Milliseconds since start time " << SDL_GetTicks() - startTime;

		txtImage->SetText("Time: " + std::to_string(timer.GetElapsedTime()));
		//

		player->Update();
		window->ClearScreen();

		window->renderer->RenderImage(txtImage, 50, 50);
		player->playerAnimation->Update();
		window->renderer->RenderAnimation(player->playerAnimation);
		

		window->UpdateWindow();
	}
}
