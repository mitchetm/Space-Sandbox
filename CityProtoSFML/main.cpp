#include <SFML/Graphics.hpp>
#include "Game.h"
#include "MenuState.h"
#include <cstdlib>
#include <ctime>


int main()
{
	//Setup random seed.
	srand(time(NULL));

	Game game;

	//Initialize the game and start at the Main Menu.
	game.pushState(new MenuState(&game));

	game.mainLoop();

	return 0;
}