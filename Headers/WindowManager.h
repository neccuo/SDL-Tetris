#pragma once

#include "BaseManager.h"

class WindowManager : BaseManager
{
public:
	WindowManager(int w, int h);
	bool init() override;
	void close() override;
	void* get() override;

	int W();
	int H();
private:
	SDL_Window* mWindow = nullptr;

	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

};