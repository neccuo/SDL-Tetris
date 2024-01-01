// memleak check
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>



#include "Headers/NTexture.h"
#include "Headers/SDLManager.h"
#include "Headers/InputHandler.h"
#include "Headers/Block.h"
#include "Headers/Compound.h"
#include "Headers/CompoundBuilder.h"



SDL_Texture* loadTexture(std::string pathIn, SDL_Renderer* rendererIn);

SDL_Texture* loadTexture(std::string pathIn, SDL_Renderer* rendererIn)
{
	SDL_Texture* texture = nullptr;

	texture = IMG_LoadTexture(rendererIn, pathIn.c_str());

	return texture;
}

int main(int argc, char* args[])
{
	SDLManager sdlManager;
	InputHandler inputHandler;
	
	if (!sdlManager.init())
	{
		printf("Failed to initialize!\n");
		return 1;
	}

	SDL_Renderer* renderer = sdlManager.getRenderer();

	//sdlManager.testAddRenderables();

	bool quit = false;

	int x = 0;
	int y = 0;

	SDL_Event mEventHandler;

	while (1)
	{
		while (SDL_PollEvent(&mEventHandler))
		{
			if (mEventHandler.type == SDL_QUIT)
				quit = true;
			else if (mEventHandler.type == SDL_KEYDOWN)
			{
				if (mEventHandler.key.keysym.sym == SDLK_ESCAPE)
					quit = true;
				if (mEventHandler.key.keysym.sym == SDLK_e)
				{
					printf("e");
					/*for (auto& c : renderables)
					{
						((Compound*)c)->rotateCw();
					}*/
				}
			}
		}
		//quit = inputHandler.handleEvents();
		if (quit)
			break;

		// Render phase
		sdlManager.render();
	}

	sdlManager.close();

#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}

