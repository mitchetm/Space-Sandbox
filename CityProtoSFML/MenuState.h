#pragma once

#include <SFML\Graphics.hpp>
#include <SFGUI\SFGUI.hpp>
#include <SFGUI\Button.hpp>
#include <iostream>
#include "GameState.h"

/*Main Menu state, move to play state when enter is pressed.*/
class MenuState : public GameState
{
public:
	MenuState(Game* game);

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void inputProcessing();

	void newGame();
	void loadGame();
private:
	sfg::SFGUI guiMain;

	bool loadSaved = false;


};
