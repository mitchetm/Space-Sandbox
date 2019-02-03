#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include <cmath>
#include "Planet.h"
#include "Game.h"
#include <cmath>
#include <iostream>
/*Class that defines a playable zone,
One quadrant of a universe*/
class Area
{
public:
	Area(void);
	Area(int numbPlanets);

	std::vector<Planet> &getPlanetVector() { return planetsList; }

	void checkForMouseHovers(Game * game);
	void drawArea(Game * game);

	int getPlanetSelectedID();
	Planet &getPlanetSelection();
	//sf::Shader &getPlanetShader();
	
private:
	int selectedPlanetID = 0;
	std::vector<Planet> planetsList;
};