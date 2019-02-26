#include "Universe.h"

//Create a specifided number of quadrants in the Universe, then fill each quadrant with a random number of planets.
void Universe::createUniverse(int numQuadrants)
{
	for (int i = 0; i < numQuadrants; i++)
	{
		
		Area newArea(rand() % 200);
		quadrants.push_back(newArea);
	}
	//quadrants[0].getPlanetShader().loadFromFile("PlanetShader.vert", "PlanetShader.frag");
}
