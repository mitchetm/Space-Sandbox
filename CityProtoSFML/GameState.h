#pragma once
#include "Game.h"

//Completely generic class
class GameState
{
public:
	Game* game;

	virtual void draw(const float dt) = 0;
	virtual void update(const float dt) = 0;
	virtual void inputProcessing() = 0;
};