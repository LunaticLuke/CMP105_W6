#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>
#include "GravityBall.h"
#include "AToB.h"
#include "AngryBird.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();
	GravityBall ballObject;
	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	AToB aToBObject;
	AngryBird birdObject;
	// More level variables
};