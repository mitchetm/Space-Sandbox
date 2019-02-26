#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <cmath>
#include <iostream>

//Player class that handles movement and player graphics.
class Player : public sf::Sprite
{
public:
	void setShipStats(float newThrust, float newDecay, int newMaxSpeed, int newTurningSpeed);
	void checkMovement(float deltaTime);
private:
	float thrust, decay;
	float maxSpeed, turningSpeed, speed;
	sf::Vector2f velocity;
	const float PI = 3.1415927;
	float xSpeed, ySpeed;
	sf::Texture shipTexture;
};