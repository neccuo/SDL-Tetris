#pragma once

#include <SDL.h>

#include <stdexcept>

// uses raw sdl shapes, no textures
class Block
{
public:
	Block(int w, int h);

	// not necessary but cool to have
	Block& operator=(const Block& other);

	void updateLocalPos(int x, int y);
	void updatePos(int x, int y);
	void movePos(int x, int y);
	void render(SDL_Renderer* renderer);

	int localX();
	int localY();

	int X();
	int Y();
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