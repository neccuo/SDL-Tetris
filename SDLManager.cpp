#include "Headers/SDLManager.h"

SDLManager::SDLManager()
{
	mWindowManager = new WindowManager(640, 480);
	mRenderManager = new RenderManager(mWindowManager);
}

bool SDLManager::init()
{
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	
	mWindowManager->init();
	mRenderManager->init();

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}
	return true;
}

void SDLManager::close()
{
	// kill compounds

	// Destroy subs
	mRenderManager->close();
	delete mRenderManager;
	mRenderManager = nullptr;

	mWindowManager->close();
	delete mWindowManager;
	mWindowManager = nullptr;

	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void* SDLManager::get()
{
	return nullptr;
}

void SDLManager::render()
{
	mRenderManager->clearScreen();
	mRenderManager->updatePos();
	mRenderManager->renderAll();
	mRenderManager->outToScreen();
}

SDL_Renderer* SDLManager::getRenderer()
{
	return (SDL_Renderer *) mRenderManager->get();
}

void SDLManager::testAddRenderables()
{
	std::vector<Renderable*> rbs = 
	{
		CompoundBuilder::L(100, 100),
		CompoundBuilder::cube(200, 100),
		CompoundBuilder::line(300, 100),
		CompoundBuilder::wasd(100, 200),
		CompoundBuilder::S(200, 200)
	};
	//rbs[0]->updatePos(100, 100);
	/*rbs[1]->updatePos(200, 100);
	rbs[2]->updatePos(300, 100);
	rbs[3]->updatePos(100, 200);
	rbs[4]->updatePos(200, 200);*/

	Renderable* gameField = new GameField(16, 16, 16, 16);
	((GameField*)gameField)->setPosByScreenSize(mWindowManager->W(), mWindowManager->H());
	//gameField->updatePos(32, 32);
	rbs.push_back(gameField);

	for (auto& rb : rbs)
	{
		mRenderManager->addRenderable(rb);
	}
}
