#pragma once

#include <SDL.h>

#include <vector>

#include "Block.h"


// each block has its own base coordinates.
// compound base coor + block base coor = block real coor
// each coordinate is based on top left (0, 0)
class Compound
{
public:
	Compound();
	Compound(std::string nameIn);
	~Compound();
	//void addBlock(Block* block);
	void addBlock(int x, int y, int w, int h);

	void updatePos(int x, int y);
	void render(SDL_Renderer* renderer);

	void rotateCw();
	void rotateCoCw();

	std::string name();

	int W();
	int H();

private:
	void updateChildPos();
	void swapWH();

	std::vector<Block*> blocks;

	std::string mName;
	int mX{ 0 };
	int mY{ 0 };
	int mW{ 0 };
	int mH{ 0 };

};