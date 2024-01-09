#pragma once

#include "Compound.h"

class CompoundBuilder
{
public:
	static Compound* L(int x = 0, int y = 0);
	static Compound* cube(int x = 0, int y = 0);
	static Compound* line(int x = 0, int y = 0);
	static Compound* wasd(int x = 0, int y = 0);
	static Compound* S(int x = 0, int y = 0);
private:
	static Compound* build(const std::vector<std::pair<int, int>>& coors, std::string name, int x, int y, int w = 16, int h = 16);
};