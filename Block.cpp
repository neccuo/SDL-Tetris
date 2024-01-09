#include "Headers/Block.h"

Block::Block(int w, int h) : mW { w }, mH { h }
{
	updateLocalPos(0, 0);
	updatePos(0, 0);
}

Block& Block::operator=(const Block& other)
{
	// Avoid self-assignment
	if (this != &other) 
	{ 
		mRect = other.mRect;
		mLocalX = other.mLocalX;
		mLocalY = other.mLocalY;
		mX = other.mX;
		mY = other.mY;
		mW = other.mW;
		mH = other.mH;
	}
	return *this;
}

Block::~Block()
{
}

void Block::updateLocalPos(int x, int y)
{
	if (x < 0 || y < 0)
	{
		throw std::exception("Local positions cannot be negative\n");
	}
	mLocalX = x;
	mLocalY = y;
}

void Block::updatePos(int x, int y)
{
	mX = x;
	mY = y;
}

void Block::render(SDL_Renderer* renderer)
{
	mRect = { mX, mY, mW, mH };
	renderFillRect(renderer);
	renderOutlineRect(renderer);
}

int Block::localX()
{
	return mLocalX;
}

int Block::localY()
{
	return mLocalY;
}

int Block::X()
{
	return mX;
}

int Block::Y()
{
	return mY;
}

int Block::W()
{
	return mW;
}

int Block::H()
{
	return mH;
}

void Block::renderFillRect(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &mRect);
}

void Block::renderOutlineRect(SDL_Renderer* renderer)
{
	// use SDL_Color
	// 100% visual, no effect on collision
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_Rect outline = {mRect.x-1, mRect.y-1, mRect.w+1, mRect.h+1};
	SDL_RenderDrawRect(renderer, &outline);
}
