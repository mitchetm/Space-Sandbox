#include "Area.h"


Area::Area(void)
{
}

Area::Area(int numbPlanets)
{
	for (int i = 0; i < numbPlanets; i++)
	{
		Planet newPlanet(rand() % 200, rand() % 255, rand() % 255, rand() % 255);
		newPlanet.setOrigin(newPlanet.getPosition().x + newPlanet.getRadius(), newPlanet.getPosition().y + newPlanet.getRadius());
		newPlanet.setPosition(rand() % 10000, rand() % 10000);
		planetsList.push_back(newPlanet);
	}
}

void Area::checkForMouseHovers(Game * game)
{
	sf::Vector2f mousePos = game->window.mapPixelToCoords(sf::Mouse::getPosition(game->window));

	for (int i = 0; i < planetsList.size(); i++)
	{
		sf::Vector2f circlePos = planetsList[i].getPosition();
		if (std::sqrt((mousePos.x - circlePos.x)*(mousePos.x - circlePos.x) +
			(mousePos.y - circlePos.y)*(mousePos.y - circlePos.y)) < planetsList[i].getRadius())
			selectedPlanetID = i;
	}
}

void Area::drawArea(Game * game)
{
	for (int i = 0; i < planetsList.size(); i++)
		game->window.draw(planetsList[i]);
}

int Area::getPlanetSelectedID()
{
	return selectedPlanetID;
}

Planet & Area::getPlanetSelection()
{
	return planetsList[selectedPlanetID];
}



