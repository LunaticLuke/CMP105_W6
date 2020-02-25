#include "GravityBall.h"

GravityBall::GravityBall()
{
	texture.loadFromFile("gfx/Beach_Ball.png");
	setTexture(&texture);
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	jumpForce = 4;
	jumpVector = sf::Vector2f(0, -jumpForce) * scale;
}

GravityBall::~GravityBall()
{
}

void GravityBall::setRenderWindow(sf::RenderWindow* rendWind)
{
	wind = rendWind;
}


void GravityBall::update(float dt) 
{
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
	stepVelocity += gravity * dt;
	setPosition(getPosition() + pos);
	
	if (getPosition().y + getSize().y  >= wind->getSize().y)
	{
		setPosition(getPosition().x, wind->getSize().y - getSize().y);
		stepVelocity = sf::Vector2f(0, 0);
		isJumping = false;
	}
}

void GravityBall::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping)
		{
			stepVelocity = jumpVector;
			isJumping = true;
		}
	}
	if (input->isMouseLDown())
	{
		
		setPosition(sf::Mouse::getPosition(*wind).x, sf::Mouse::getPosition(*wind).y);
	}
}
