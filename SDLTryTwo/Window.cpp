#include "Window.h"
Window::Window() {
	width = DEFAULT_SCREEN_WIDTH;
	height = DEFAULT_SCREEN_HEIGHT;
}

Window::Window(int _width, int _height)
{
	width = _width;
	height = _height;
}

Window::~Window() {

	//Destroy window
	SDL_DestroyRenderer(renderer->sdl_Renderer);
	SDL_DestroyWindow(sdl_Window);
}

void Window::ClearScreen()
{
	SDL_RenderClear(renderer->sdl_Renderer);
}

void Window::SetSdlWindow(SDL_Window* _sdlWindow)
{
	sdl_Window = _sdlWindow;
	sdl_ScreenSurface = SDL_GetWindowSurface(sdl_Window);
}

void Window::FillWindow(SDL_Rect* rect, Uint32 color)
{
	SDL_FillRect(sdl_ScreenSurface, rect, color);
}

void Window::UpdateWindow()
{
	//SDL_UpdateWindowSurface(sdl_Window);
	SDL_RenderPresent(renderer->sdl_Renderer);
}