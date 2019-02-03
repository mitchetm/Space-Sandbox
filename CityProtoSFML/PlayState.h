#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <iostream>
#include <vector>
#include "GameState.h"
#include "Universe.h"
#include "Player.h"


class PlayState : public GameState
{
public:
	PlayState(Game* game);

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void inputProcessing();

	void mouseButtonFunctionality(); //For planet clicking
private:
	bool editorState = false;
	bool selectedPlanet = false;
	bool pauseLogic = false;
	Universe universeManager;
	sf::RectangleShape shipShape;
	int cam_speed = 500;
	sf::Clock clock;
	sf::View gameCam;
	Player ship;

	void pauseGame();
};