#include "PlayState.h"

PlayState::PlayState(Game * game)
{
	this->game = game;
	universeManager.createUniverse(1);
	gameCam.reset(sf::FloatRect(0, 0, game->window.getSize().x, game->window.getSize().y));
	//gameCam.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	ship.setShipStats(1, .97, 2, 100);
	ship.setOrigin(40, 40);
	ship.setPosition(universeManager.getQuadrants()[0].getPlanetVector()[0].getPosition());
	gameCam.zoom(2);
	//shipShape.setSize(sf::Vector2f(200, 400));
	//ship.setPosition(200, 200);
}

void PlayState::draw(const float dt)
{
	universeManager.getQuadrants()[0].drawArea(game);
	//game->window.draw(shipShape);
	game->window.draw(ship);
}

void PlayState::update(const float dt)
{
	if (pauseLogic == false)
	{
		universeManager.getQuadrants()[0].checkForMouseHovers(game);
		ship.checkMovement(dt);
	}
}

void PlayState::inputProcessing()
{
	sf::Event event;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
			/* Close the window */
		case sf::Event::Closed:
			this->game->window.close();
			break;

			//pause game
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				pauseGame();
			break;

		case sf::Event::Resized:
			gameCam.reset(sf::FloatRect(0, 0, event.size.width, event.size.height)); 
			this->game->window.setView(gameCam);
			break;
		}
	}

	if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonReleased)
			mouseButtonFunctionality();


	float frametime = clock.getElapsedTime().asSeconds();

	clock.restart();
	gameCam.setCenter(ship.getPosition());
	game->window.setView(gameCam);

}

void PlayState::mouseButtonFunctionality()
{
	if (universeManager.getQuadrants()[0].getPlanetSelectedID() >= 0 && selectedPlanet == false && editorState == false)
	{
		selectedPlanet = true;
		universeManager.getQuadrants()[0].getPlanetSelection().setOutlineColor(sf::Color::White);
		universeManager.getQuadrants()[0].getPlanetSelection().setOutlineThickness(10);
		std::cout << "Found Planet with ID: " << universeManager.getQuadrants()[0].getPlanetSelectedID() << std::endl;
	}
}


void PlayState::pauseGame()
{
}
