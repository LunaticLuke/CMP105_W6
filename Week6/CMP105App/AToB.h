#include "Framework/Vector.h"
#include "Framework/GameObject.h"


#pragma once
class AToB : public GameObject
{
public:
	AToB();
	~AToB();
	void update(float dt) override;
	void handleInput(float dt) override;
	void setRenderWindow(sf::RenderWindow* rendWind);
private:
	sf::Vector2f pointA;
	sf::Vector2f pointB;
	float speed = 3;
	sf::RenderWindow* wind;
	sf::Texture texture;
	sf::Vector2f direction;
	sf::Vector2f stepVelocity;
	float acceleration = 2.0f;
};

