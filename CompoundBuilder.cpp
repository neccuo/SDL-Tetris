#include "Headers/CompoundBuilder.h"

Compound* CompoundBuilder::L()
{
	std::vector<std::pair<int, int>> coors
	{
		{0,0},
		{0,1},
		{0,2},
		{1,2}
	};

	return build(coors, "L");
}

Compound* CompoundBuilder::cube()
{
	std::vector<std::pair<int, int>> coors
	{
		{0,0},
		{0,1},
		{1,0},
		{1,1}
	};

	return build(coors, "CUBE");
}

Compound* CompoundBuilder::line()
{
	std::vector<std::pair<int, int>> coors
	{
		{0,0},
		{0,1},
		{0,2},
		{0,3}
	};

	return build(coors, "LINE");
}

Compound* CompoundBuilder::wasd()
{
	std::vector<std::pair<int, int>> coors
	{
		{0,0},
		{0,1},
		{0,2},
		{1,1}
	};

	return build(coors, "WASD");
}

Compound* CompoundBuilder::S()
{
	std::vector<std::pair<int, int>> coors
	{
		{0,0},
		{1,0},
		{1,1},
		{2,1}
	};

	return build(coors, "S");
}

Compound* CompoundBuilder::build(std::vector<std::pair<int, int>> coors, std::string name, int w, int h)
{
	Compound* compound = new Compound(name);

	for (const auto& pr: coors)
	{
		int i = pr.first;
		int j = pr.second;
		compound->addBlock(i * w, j * h, w, h);
	}

	printf("%s\tdimensions (%d, %d)\n", compound->name().c_str(), compound->W(), compound->H());

	return compound;
}