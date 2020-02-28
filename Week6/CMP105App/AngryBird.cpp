#include "AngryBird.h"
#include <iostream>

AngryBird::AngryBird()
{
	texture.loadFromFile("gfx/MushroomTrans.png");
	setTexture(&texture);
	setSize(sf::Vector2f(30, 30));
	setScale(1, 1);
	setPosition(50, 250);
	gravity = sf::Vector2f(0, 9.8f) * scale;
}

AngryBird::~AngryBird()
{
}

void AngryBird::handleInput(float dt)
{
	if (input->isMouseLDown() && !isDragging)
	{
		isDragging = true;
		startPoint = sf::Vector2f(input->getMouseX(), input->getMouseY());
	}
	else if(!input->isMouseLDown() && isDragging)
	{
		isDragging = false;
		target = sf::Vector2f(input->getMouseX(), input->getMouseY());
		inAir = true;
	}
}

void AngryBird::update(float dt)
{
	if (inAir)
	{
		direction = target - getPosition();
		speed = Vector::magnitude(direction);
		direction = Vector::normalise(direction);
		velocity = direction * speed;
		setPosition(getPosition() + (velocity * dt));
	}

	applyGravity(dt);
	
	if (getPosition().x <= 0)
	{
		setPosition(0, getPosition().y);
		velocity.x = velocity.x/ 1.2f;
		
	}
	 if((getPosition().x + getSize().x)  >= wind->getSize().x)
	{
		 setPosition(wind->getSize().x - getSize().x, getPosition().y);
		velocity.x = (-velocity.x) / 1.2f;
		
	}
	 if (getPosition().y <= 0)
	{
		 setPosition(getPosition().x, wind->getSize().y);
		velocity.y = (-velocity.y) / 1.2f;
		
	}
	 if ((getPosition().y + getSize().y) >= wind->getSize().y )
	{
		inAir = false;
		setPosition(getPosition().x, wind->getSize().y - getSize().y);
		stepVelocity = sf::Vector2f(0, 0);
	}
	
}

void AngryBird::setRenderWindow(sf::RenderWindow* rendWind)
{
	wind = rendWind;
}

void AngryBird::applyGravity(float dt)
{
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
	stepVelocity += gravity * dt;
	setPosition(getPosition() + pos);
}
