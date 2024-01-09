#pragma once

#include <SDL.h>

class Renderable
{
public:
	virtual void updatePos(int x, int y) = 0;
	virtual void render(SDL_Renderer* renderer) = 0;
	virtual int X() = 0;
	virtual int Y() = 0;

	virtual ~Renderable() {};
};