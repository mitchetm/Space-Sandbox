#include "Area.h"


Area::Area(void)
{
}

//Create a new area filled with planets.
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

//Check if any planets are being hovered over by the mouse.
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

//Draws the planets to the buffer for this area.
void Area::drawArea(Game * game)
{
	for (int i = 0; i < planetsList.size(); i++)
		game->window.draw(planetsList[i]);
}

//Get ID for the planet.
int Area::getPlanetSelectedID()
{
	return selectedPlanetID;
}

//Return the currently selected planet.
Planet & Area::getPlanetSelection()
{
	return planetsList[selectedPlanetID];
}



