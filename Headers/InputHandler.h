#pragma once

#include <SDL.h>

enum class GameState { NullState, MenuState, PlayState};

class InputHandler
{
public:
	// true if quit
	// use enums at some point
	bool handleEvents();

private:
	SDL_Event mEventHandler;
};