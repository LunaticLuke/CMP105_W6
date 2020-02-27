#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballObject.setSize(sf::Vector2f(50, 50));
	ballObject.setPosition(50, 50);
	ballObject.setScale(1,1);
	ballObject.setRenderWindow(window);
	ballObject.setInput(input);
	aToBObject.setRenderWindow(window);
	aToBObject.setPosition(0, window->getSize().y);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ballObject.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ballObject.update(dt);
	aToBObject.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ballObject);
	window->draw(aToBObject);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}