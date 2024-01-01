#include "Headers/RenderManager.h"

RenderManager::RenderManager(WindowManager* wManager) : mWindowManager { wManager }
{
}

bool RenderManager::init()
{
	SDL_Window* window = (SDL_Window*)mWindowManager->get();
	mRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (mRenderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	return true;
}

void RenderManager::close()
{
	for (auto& r : renderables)
	{
		if (r != nullptr)
		{
			delete r;
			r = nullptr;
		}
	}
	renderables.clear();

	SDL_DestroyRenderer(mRenderer);
	mRenderer = nullptr;
}

void* RenderManager::get()
{
	return mRenderer;
}

void RenderManager::clearScreen()
{
	SDL_SetRenderDrawColor(mRenderer, 0x7F, 0x7F, 0x7F, 0xFF);
	SDL_RenderClear(mRenderer);
}

void RenderManager::updatePos()
{
	for (auto& r : renderables)
	{
		r->updatePos(r->X(), r->Y());
	}
	/*renderables[0]->updatePos(100, 100);
	renderables[1]->updatePos(200, 100);
	renderables[2]->updatePos(300, 100);
	renderables[3]->updatePos(100, 200);
	renderables[4]->updatePos(200, 200);*/
}

void RenderManager::renderAll()
{
	for (auto& r : renderables)
	{
		r->render(mRenderer);
	}
}

void RenderManager::outToScreen()
{
	SDL_RenderPresent(mRenderer);
}

void RenderManager::addRenderable(Renderable* renderable)
{
	renderables.push_back(renderable);
}
