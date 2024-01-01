#pragma once

#include <vector>

#include "Renderable.h"

#include "BaseManager.h"
#include "WindowManager.h"

class RenderManager : BaseManager
{
public:
	RenderManager(WindowManager* wManager);
	bool init() override;
	void close() override;
	void* get() override;

	// Rendering logics

	void clearScreen();		// Clear screen phase
	void updatePos();		// Move renderables (give parameters to it later...)
	void renderAll();		// Render phase
	void outToScreen();		// Update screen

	void addRenderable(Renderable* renderable);
private:
	WindowManager* mWindowManager = nullptr;

	SDL_Renderer* mRenderer = nullptr;

	// maybe use a pq to get the hierarchy
	std::vector<Renderable*> renderables;
};