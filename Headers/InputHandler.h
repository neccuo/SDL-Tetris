#pragma once

#include <SDL.h>

class InputHandler
{
public:
	// true if quit
	// use enums at some point
	bool handleEvents();

private:
	SDL_Event mEventHandler;
};