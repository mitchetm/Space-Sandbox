#include "Planet.h"

//Set up Planet given color and size.
Planet::Planet(int seedGenSize, int seedGenColorR, int seedGenColorG, int seedGenColorB)
{
	this->setRadius(seedGenSize);
	this->setFillColor(sf::Color(seedGenColorR, seedGenColorG, seedGenColorB));
}

int Planet::getPlanetSize()
{
	return this->getRadius();
}

void Planet::setPlanetRadius(int newRadius)
{
	this->setRadius(newRadius);
}

sf::Color Planet::getPlanetColor()
{
	return this->getFillColor();
}

void Planet::setPlanetColor(sf::Color &newColor)
{
	this->setFillColor(newColor);
}

void Planet::setPlanetPosition(sf::Vector2f &newPos)
{
	this->setPosition(newPos);
}

sf::Vector2f Planet::getPlanetPosition()
{
	return this->getPosition();
}

std::string Planet::getPlanetName()
{
	return planetName;
}

void Planet::setPlanetName(std::string newPlanetName)
{
	planetName = newPlanetName;
}