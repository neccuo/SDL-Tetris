#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <stdio.h>

class SDLManager
{
public:
	SDLManager();
	bool init();
	void close();
	SDL_Renderer* getRenderer();
private:
	SDL_Window* mWindow = nullptr;

	SDL_Renderer* mRenderer = nullptr;

	// Carry those to somewhere else at some point
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
};