#include "Game.h"
#include "GameState.h"

//Create a new window.
Game::Game()
{
	window.create(sf::VideoMode(1920, 1080), "CityProto");

	window.setFramerateLimit(60);
}

//Allow a state to be pushed onto the stack.
void Game::pushState(GameState* handleState)
{
	ourStates.push_back(handleState);
}

//Pop state off of stack.
void Game::popState()
{
	ourStates.back();
	delete ourStates.back();
	ourStates.pop_back();
}

//Remove states when game is closed.
Game::~Game()
{
	while (!ourStates.empty())
		popState();
}

//Get the current state.
GameState* Game::currentState()
{
	if (ourStates.empty())
		return nullptr;
	else
		return ourStates.back();
}

//Main loop for handling states.
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