#include <SFML/Graphics.hpp>
#include "Game.h"
#include "MenuState.h"
#include <cstdlib>
#include <ctime>


int main()
{
	srand(time(NULL)); //Replace time(NULL) with actual seed, given by server masters or other users

	Game game;

	game.pushState(new MenuState(&game));

	game.mainLoop();

	return 0;
}