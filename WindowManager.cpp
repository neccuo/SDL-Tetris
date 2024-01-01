#include "Headers/WindowManager.h"

WindowManager::WindowManager(int w, int h) : SCREEN_WIDTH{w}, SCREEN_HEIGHT{h}
{

}

bool WindowManager::init()
{
	mWindow = SDL_CreateWindow("YOYOYO TETRIS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (mWindow == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	return true;
}

void WindowManager::close()
{
	SDL_DestroyWindow(mWindow);
	mWindow = nullptr;
}

void* WindowManager::get()
{
	return mWindow;
}

//SDL_Window* WindowManager::getWindow()
//{
//	return mWindow;
//}

int WindowManager::W()
{
	return SCREEN_WIDTH;
}

int WindowManager::H()
{
	return SCREEN_HEIGHT;
}

