#pragma once

#include "SDLManager.h"
#include "Renderable.h"

class GameField : public Renderable
{
public:
	GameField(int outlineW, int outlineH, int blockW, int blockH);
	~GameField() override;
	void setPosByScreenSize(int screenW, int screenH);

	void updatePos(int x, int y) override;
	void render(SDL_Renderer* renderer) override;
	int X() override;
	int Y() override;
private:
	int mX{ 0 };
	int mY{ 0 };
	int mW{ 0 };
	int mH{ 0 };
	SDL_Rect rLeft, rUp, rRight, rDown;
};