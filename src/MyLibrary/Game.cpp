#include "../../include/MyLibrary/Game.h"

Game::Game() {

	// all tiles are accesable
	EmptyTileGenerator &ETG = EmptyTileGenerator::getInstance();
	ETG.setField(this->width, this->height);

	// initializes snake by placing its head on a map
	auto tile = ETG.getEmptyTile();
	this->snake = new Snake();

	// initializes froots
	for (int i = 0; i < this->fruitNum; i++) {
		this->fruits.insert(Fruit(ETG.getEmptyTile()));
	}

}

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