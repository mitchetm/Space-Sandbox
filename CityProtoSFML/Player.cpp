#include "Player.h"

void Player::setShipStats(float newThrust, float newDecay, int newMaxSpeed, int newTurningSpeed)
{
	thrust = newThrust;
	decay = newDecay;
	maxSpeed = newMaxSpeed;
	turningSpeed = newTurningSpeed;

	if (!shipTexture.loadFromFile("DurrrSpaceShip.png"))
	{

	}

	shipTexture.setSmooth(true);
	this->setTexture(shipTexture);

	speed = 0;
	velocity = sf::Vector2f(0, 0);
	xSpeed = 0;
	ySpeed = 0;
}

void Player::checkMovement(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->rotate(turningSpeed * deltaTime);
		xSpeed *= decay;
		ySpeed *= decay;
		//xSpeed += thrust*std::sin(this->getRotation()*(PI / 180));
		//ySpeed += thrust*std::cos(this->getRotation()*(PI / 180));
		//std::cout << "Reading rotation right " << (turningSpeed) << std::endl;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->rotate(-(turningSpeed*deltaTime));
		xSpeed *= decay;
		ySpeed *= decay;
		//xSpeed += thrust*std::sin(this->getRotation()*(PI / 180));
		//ySpeed += thrust*std::cos(this->getRotation()*(PI / 180));
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		xSpeed += thrust*std::sin(this->getRotation()*(PI / 180));
		ySpeed += thrust*std::cos(this->getRotation()*(PI / 180));
	}

	else
	{
		//xSpeed += thrust*std::sin(this->getRotation()*(PI / 180));
		//ySpeed += thrust*std::cos(this->getRotation()*(PI / 180));
		xSpeed *= decay;
		ySpeed *= decay;
	}


	speed = std::sqrt((xSpeed*xSpeed) + (ySpeed*ySpeed));
	if (speed > maxSpeed)
	{
		xSpeed *= maxSpeed / speed;
		ySpeed *= maxSpeed / speed;
	}
	velocity = this->getPosition();
	this->setPosition((velocity.x += xSpeed), (velocity.y -= ySpeed));
}