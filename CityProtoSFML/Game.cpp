#include "Game.h"
#include "GameState.h"
Game::Game()
{
	window.create(sf::VideoMode(1920, 1080), "CityProto");

	window.setFramerateLimit(60);
}

void Game::pushState(GameState* handleState)
{
	ourStates.push_back(handleState);
}

void Game::popState()
{
	ourStates.back();
	delete ourStates.back();
	ourStates.pop_back();
}

Game::~Game()
{
	while (!ourStates.empty())
		popState();
}

GameState* Game::currentState()
{
	if (ourStates.empty())
		return nullptr;
	else
		return ourStates.back();
}

void Game::mainLoop()
{
	sf::Clock clock;

	while (window.isOpen())
	{
		//control frame rate (you can ignore this stuff for now)
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		//exception handling
		if (currentState() == nullptr)
			continue;

		//get user input for current game state
		currentState()->inputProcessing();

		//update anything neccessary
		currentState()->update(dt);

		//clear window
		window.clear();

		//draw anything in the current game state
		currentState()->draw(dt);

		window.display();
	}
}