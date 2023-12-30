#pragma once

#include "Compound.h"

class CompoundBuilder
{
public:
	static Compound* L();
	static Compound* cube();
	static Compound* line();
	static Compound* wasd();
	static Compound* S();
private:
	static Compound* build(std::vector<std::pair<int, int>> coors, std::string name, int w = 16, int h = 16);
};