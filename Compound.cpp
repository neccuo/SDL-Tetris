#include "Headers/Compound.h"

Compound::Compound() : mName{ "UCompound" }
{
	updatePos(0, 0);
}

Compound::Compound(std::string nameIn) : mName{ nameIn }
{
	updatePos(0, 0);
}

Compound::~Compound()
{
	for (Block*& b : blocks)
	{
		if (b != nullptr)
		{
			delete b;
			b = nullptr;
		}
	}
	blocks.clear();
}

//void Compound::addBlock(Block* block)
//{
//	blocks.push_back(block);
//	mW = std::max(block->localX() + block->W(), mW);
//	mH = std::max(block->localY() + block->H(), mH);
//}

void Compound::addBlock(int x, int y, int w, int h)
{
	Block* block = new Block(w, h);
	block->updateLocalPos(x, y);
	blocks.push_back(block);
	mW = std::max(x + w, mW);
	mH = std::max(y + h, mH);
}

// update base compound coors, then child coors relative to compound
void Compound::updatePos(int x, int y)
{
	mX = x;
	mY = y;

	updateChildPos();
}

void Compound::render(SDL_Renderer* renderer)
{
	for (Block* b : blocks)
	{
		b->render(renderer);
	}
}

void Compound::rotateCw()
{
	swapWH();
	for (Block* b : blocks)
	{
		int x = b->localX();
		int y = b->localY();

		int newX = -y + mW;
		int newY = x;
		b->updateLocalPos(newX, newY);
	}
}
 
std::string Compound::name()
{
	return mName;
}

int Compound::W()
{
	return mW;
}

int Compound::H()
{
	return mH;
}

void Compound::updateChildPos()
{
	for (Block* b : blocks)
	{
		b->updatePos(mX + b->localX(), mY + b->localY());
	}
}

void Compound::swapWH()
{
	int temp = mW;
	mW = mH;
	mH = temp;
}

