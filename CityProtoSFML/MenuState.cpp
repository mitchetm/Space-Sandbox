#include <SFML\Graphics.hpp>
#include "MenuState.h"
#include "GameState.h"
#include "PlayState.h"

MenuState::MenuState(Game* game)
{
	this->game = game;

	auto newGameButton = sfg::Button::Create("New Game");
	newGameButton->SetPosition(sf::Vector2f(1030.f, 800.f));
	newGameButton->GetSignal(sfg::Widget::OnLeftClick).Connect([this] { this->newGame(); });
}

void MenuState::inputProcessing()
{
	sf::Event event;

	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
			/* Close the window */
		case sf::Event::Closed:
			game->window.close();
			break;

			/* Change Between game states */
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				game->window.close();
			else if (event.key.code == sf::Keyboard::Return)
				newGame();
			break;

		}

	}
}

void MenuState::update(const float dt)
{

}

void MenuState::draw(const float dt)
{
	guiMain.Display(game->window);
}

void MenuState::loadGame()
{

}

void MenuState::newGame()
{
	game->pushState(new PlayState(game));
}