#include "Framework/GameObject.h"
#include "Framework/Vector.h"

#pragma once
class GravityBall : public GameObject
{
public:
	GravityBall();
	~GravityBall();
	void setRenderWindow(sf::RenderWindow* rendWind);
	void update(float dt) override;
	void handleInput(float dt) override;
private:
	sf::Texture texture;
	float scale = 25.f;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::Vector2f jumpVector;
	sf::RenderWindow* wind;
	int jumpForce;
	bool isJumping;
	
};

