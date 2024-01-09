#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "BaseManager.h"
#include "WindowManager.h"
#include "RenderManager.h"

#include "Block.h"
#include "Compound.h"
#include "CompoundBuilder.h"
#include "GameField.h"


class SDLManager : BaseManager
{
public:
	SDLManager();
	bool init() override;
	void close() override;
	void* get() override;

	void update();
	void render();

	SDL_Renderer* getRenderer();
	void testAddRenderables();
private:
	// heap allocate maybe???
	WindowManager* mWindowManager;

	RenderManager* mRenderManager;

	// Carry those to somewhere else at some point
	/*const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;*/
};