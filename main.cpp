#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>

#include "Headers/NTexture.h";
#include "Headers/SDLManager.h";
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

	std::vector<Compound*> compounds
	{
		CompoundBuilder::L(),
		CompoundBuilder::cube(),
		CompoundBuilder::line(),
		CompoundBuilder::wasd(),
		CompoundBuilder::S()
	};


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
					for (const auto& c : compounds)
					{
						c->rotateCw();
					}
				}
			}
		}
		//quit = inputHandler.handleEvents();
		if (quit)
			break;


		// Clear screen
		SDL_SetRenderDrawColor(renderer, 0x7F, 0x7F, 0x7F, 0xFF);
		SDL_RenderClear(renderer);

		// Update phase
		//boxComp.updatePos(x++, y++);
		compounds[0]->updatePos(100, 100);
		compounds[1]->updatePos(200, 100);
		compounds[2]->updatePos(300, 100);
		compounds[3]->updatePos(100, 200);
		compounds[4]->updatePos(200, 200);

		// Render phase
		for(auto& c : compounds)
		{
			c->render(renderer);
		}

		// Update screen
		SDL_RenderPresent(renderer);
	}

	for (auto& c : compounds)
	{
		if (c != nullptr)
		{
			delete c;
			c = nullptr;
		}
	}

	compounds.clear();

	sdlManager.close();

	return 0;
}

