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

#include <iostream>

// Global new operator overload
void* operator new(size_t size) 
{
	void* ptr = malloc(size);
	std::cout << "Memory allocated in\t0x" << ptr << ". Size: " << size << " bytes." << std::endl;
	return ptr; // Use malloc for memory allocation
}

// Global delete operator overload
void operator delete(void* ptr) noexcept 
{
	std::cout << "Memory deallocated in\t0x" << ptr << "." << std::endl;
	free(ptr); // Use free for memory deallocation
}


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

	sdlManager.testAddRenderables();

	bool quit = false;

	int x = 0;
	int y = 0;

	SDL_Event mEventHandler;

	// same as
	/*Renderable* lShape = CompoundBuilder::L();
	lShape->updatePos(100, 100);*/

	std::vector<std::pair<int, int>> coors
	{
		{0,0},
		{0,1},
		{0,2},
		{1,2}
	};

	//Compound* compound = new Compound("L");
	int w = 16;
	int h = 16;

	/*for (const auto& pr : coors)
	{
		int i = pr.first;
		int j = pr.second;
		compound->addBlock(i * w, j * h, w, h);
	}*/

	//printf("%s\tdimensions (%d, %d)\n", compound->name().c_str(), compound->W(), compound->H());

	//Renderable* lShape = compound;


	/*printf("Sizeof [Block]: %d\n", sizeof(Block));
	printf("Sizeof [Compound]: %d\n", sizeof(Compound));
	printf("Sizeof [Renderable]: %d\n", sizeof(Renderable));*/

	//std::cout << sizeof(std::pair<int, int>) << std::endl;

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

		// Update phase

		// Render phase
		sdlManager.render();
	}

	sdlManager.close();

	_CrtDumpMemoryLeaks();

	return 0;
}

