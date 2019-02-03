#include "Universe.h"

void Universe::createUniverse(int numQuadrants)
{
	for (int i = 0; i < numQuadrants; i++)
	{
		
		Area newArea(rand() % 200);
		quadrants.push_back(newArea);
	}
	//quadrants[0].getPlanetShader().loadFromFile("PlanetShader.vert", "PlanetShader.frag");
}
