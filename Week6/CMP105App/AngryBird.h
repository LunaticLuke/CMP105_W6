#include "Framework/Vector.h"
#include "Framework/GameObject.h"

#pragma once
class AngryBird : public GameObject
{
public:
	AngryBird();
	~AngryBird();
	void handleInput(float dt) override;
	void update(float dt) override;
	void setRenderWindow(sf::RenderWindow* rendWind);
	void applyGravity(float dt);
private:
	sf::Texture texture;
	sf::Vector2f direction;
	sf::Vector2f target;
	sf::Vector2f startPoint;
	float speed;
	bool isDragging = false;
	bool inAir = false;
	sf::RenderWindow* wind;
	sf::Vector2f gravity;
	float scale = 25.f;
	sf::Vector2f stepVelocity;
};

