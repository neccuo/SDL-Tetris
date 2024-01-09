#include "Headers/CompoundBuilder.h"

Compound* CompoundBuilder::L(int x, int y)
{
	std::vector<std::pair<int, int>> coors
	{
		{0,0},
		{0,1},
		{0,2},
		{1,2}
	};

	return build(coors, "L", x, y);
}

Compound* CompoundBuilder::cube(int x, int y)
{
	std::vector<std::pair<int, int>> coors
	{
		{0,0},
		{0,1},
		{1,0},
		{1,1}
	};

	return build(coors, "CUBE", x, y);
}

Compound* CompoundBuilder::line(int x, int y)
{
	std::vector<std::pair<int, int>> coors
	{
		{0,0},
		{0,1},
		{0,2},
		{0,3}
	};

	return build(coors, "LINE", x, y);
}

Compound* CompoundBuilder::wasd(int x, int y)
{
	std::vector<std::pair<int, int>> coors
	{
		{0,0},
		{0,1},
		{0,2},
		{1,1}
	};

	return build(coors, "WASD", x, y);
}

Compound* CompoundBuilder::S(int x, int y)
{
	std::vector<std::pair<int, int>> coors
	{
		{0,0},
		{1,0},
		{1,1},
		{2,1}
	};

	return build(coors, "S", x, y);
}

Compound* CompoundBuilder::build(const std::vector<std::pair<int, int>>& coors, std::string name, int x, int y, int w, int h)
{
	Compound* compound = new Compound(name);
	compound->updatePos(x, y);

	for (const auto& pr: coors)
	{
		int i = pr.first;
		int j = pr.second;
		compound->addBlock(i * w, j * h, w, h);
	}

	printf("%s\tdimensions (%d, %d)\n", compound->name().c_str(), compound->W(), compound->H());

	return compound;
}