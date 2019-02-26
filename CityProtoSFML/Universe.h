#pragma once
#include "Area.h"

/*Container for multiple Quadrants that contain areas.*/
class Universe
{
public:

	void createUniverse(int numQuadrants);
	std::vector<Area> &getQuadrants() { return quadrants; }
private:

	std::vector<Area> quadrants;
};