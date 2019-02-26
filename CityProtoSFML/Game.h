#pragma once

#include<vector>
#include<SFML\Graphics.hpp>
#include<SFML\System.hpp>
#include<SFML\Window.hpp>

class GameState;

/*Handles states of the game.*/
class Game
{
public:
	Game();
	~Game();

	void pushState(GameState* handleState);
	void popState();

	GameState* currentState();

	void mainLoop();

	sf::RenderWindow window;

private:
	std::vector<GameState*> ourStates;
};