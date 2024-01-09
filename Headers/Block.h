#pragma once

#include <SDL.h>

#include <stdexcept>

#include "Renderable.h"


// uses raw sdl shapes, no textures
class Block : public Renderable
{
public:
	Block(int w, int h);
	~Block() override;

	// not necessary but cool to have
	Block& operator=(const Block& other);

	void updateLocalPos(int x, int y);

	void updatePos(int x, int y) override;
	void render(SDL_Renderer* renderer) override;

	int localX();
	int localY();

	int X() override;
	int Y() override;
	int W();
	int H();

private:
	void renderFillRect(SDL_Renderer* renderer);
	void renderOutlineRect(SDL_Renderer* renderer);

	SDL_Rect mRect;

	// should be positive
	int mLocalX = 0;
	int mLocalY = 0;

	// global x
	int mX = 0;
	int mY = 0;
	// not const but don't change
	int mW;
	int mH;
};