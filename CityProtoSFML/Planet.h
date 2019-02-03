#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <cstdlib>
#include <ctime>
/*Defines a planet, circular object placed randomly inside an area,
in which an area is a quadrant of the universe
*/
class Planet : public sf::CircleShape
{
public:
	Planet(int seedGenSize, int seedGenColorR, int seedGenColorG, int seedGenColorB);

	int getPlanetSize();
	void setPlanetRadius(int newRadius);

	sf::Color getPlanetColor();
	void setPlanetColor(sf::Color &newColor);

	void setPlanetPosition(sf::Vector2f &newPos);
	sf::Vector2f getPlanetPosition();

	std::string getPlanetName();
	void setPlanetName(std::string newPlanetName);

private:
	//Planet Statistics

	std::string planetName;
};