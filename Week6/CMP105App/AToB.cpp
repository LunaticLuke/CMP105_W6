#include "AToB.h"

AToB::AToB()
{
	
	texture.loadFromFile("gfx/Goomba.png");
	setTexture(&texture);
	setSize(sf::Vector2f(50,50));
	setScale(1, 1);
	//setOrigin(sf::Vector2f(getSize().x, 0));
	setOrigin(sf::Vector2f(getSize().x / 2, getSize().y / 2));
}

AToB::~AToB()
{
}

void AToB::update(float dt)
{
#pragma region Question3

	/*pointA = sf::Vector2f(getPosition());
	pointB = sf::Vector2f(wind->getSize().x, 0);
	direction = pointB - pointA;
	Vector::normalise(direction);
	stepVelocity = (direction * speed);
	setPosition(getPosition() + (stepVelocity * dt));
	if (Vector::magnitude(pointB - getPosition()) <= 0.f)
	{
		setPosition(pointB);
	}*/
#pragma endregion
#pragma endregion
	pointA = getPosition();
	pointB.x = sf::Mouse::getPosition(*wind).x;
	pointB.y = sf::Mouse::getPosition(*wind).y;
	direction = pointB - pointA;
	Vector::normalise(direction);
	stepVelocity += (acceleration * direction) * dt;
	setPosition(getPosition() + (stepVelocity * dt));
	if (Vector::magnitude(pointB - pointA) <= 10.f)
	{
		stepVelocity = sf::Vector2f(0,0);
	}
}


void AToB::handleInput(float dt)
{
}

void AToB::setRenderWindow(sf::RenderWindow* rendWind)
{
	wind = rendWind;
}


