#pragma once
#include "Area.h"

class Universe
{
public:

	void createUniverse(int numQuadrants);
	std::vector<Area> &getQuadrants() { return quadrants; }
private:

	std::vector<Area> quadrants;
};