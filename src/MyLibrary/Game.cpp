#include "../../include/MyLibrary/Game.h"

void Game::draw() {

}

void Game::update() {
	// snake.move()
	// check if ate a fruit
	// update FruitGenerator info?? 
	// generate new fruit if necessary
}

sf::Vector2u Game::getFieldSize() {
	return sf::Vector2u(this->width, this->height);
}