#include "Headers/GameField.h"

GameField::GameField(int outlineW, int outlineH, int blockW, int blockH)
{
	// gamespace should be 10x20 no matter what
	mW = 10 * blockW + 2 * outlineW;
	mH = 20 * blockH + 2 * outlineH;

	rLeft =	
	{ 
		mX, 
		mY, 
		outlineW, 
		mH 
	};
	rUp	= 
	{ 
		mX,
		mY, 
		mW, 
		outlineH 
	};
	rRight = 
	{ 
		mX + mW - outlineW, 
		mY, 
		outlineW,
		mH 
	};
	rDown =	
	{ 
		mX, 
		mY + mH - outlineH,
		mW, 
		outlineH
	};
}

GameField::~GameField()
{

}

void GameField::setPosByScreenSize(int screenW, int screenH)
{
	int x = screenW / 2 - mW / 2;
	int y = screenH / 2 - mH / 2;
	updatePos(x, y);
}

void GameField::updatePos(int x, int y)
{
	int diffX = mX - x;
	int diffY = mY - y;

	mX = x;
	mY = y;

	rLeft.x -= diffX;
	rUp.x -= diffX;
	rRight.x -= diffX;
	rDown.x -= diffX;

	rLeft.y -= diffY;
	rUp.y -= diffY;
	rRight.y -= diffY;
	rDown.y -= diffY;
}

void GameField::render(SDL_Renderer* renderer)
{
	//int w = 10 * 16 + 2 * 16;
	//int h = 20 * 16 + 2 * 16;
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
	//SDL_Rect left, up, right, down;
	

	SDL_RenderFillRect(renderer, &rLeft);
	SDL_RenderFillRect(renderer, &rUp);
	SDL_RenderFillRect(renderer, &rRight);
	SDL_RenderFillRect(renderer, &rDown);
}

int GameField::X()
{
	return mX;
}

int GameField::Y()
{
	return mY;
}
