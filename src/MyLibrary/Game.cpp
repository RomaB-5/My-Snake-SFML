#include "../../include/MyLibrary/Game.h"

// initializes the game
Game::Game() {

	TextureManager::getInstance().loadTexture("fruit", "D:\\Університет\\SFML\\My-Snake-SFML\\assets\\textures\\apple-red.png");
	TextureManager::getInstance().loadTexture("snake-green", "D:\\Університет\\SFML\\My-Snake-SFML\\assets\\textures\\snake-green.png");

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

void Game::draw(sf::RenderWindow &window, int xCells, int yCells) {
	for (auto fruit : this->fruits) {
		fruit.draw(window, xCells, yCells);
	}

	snake->draw(window, xCells, yCells);
}

void Game::update() {
	this->snake->move();
	// check if snake is alive
	if (this->snake->head()->x < 0 || this->snake->head()->x >= this->width ||
		this->snake->head()->y < 0 || this->snake->head()->y >= this->height) {
		// TODO: game over
	}
	// check if ate a fruit
	auto head = this->snake->head();
	if (this->fruits.find(Fruit(head->x, head->y)) != this->fruits.end()) {
		// snake grows
		snake->grow();
		// remove fruit from set
		EmptyTileGenerator::getInstance().EraseTile(sf::Vector2u(head->x, head->y));
		// add new fruit
		this->fruits.insert(Fruit(EmptyTileGenerator::getInstance().getEmptyTile()));
	}

}

sf::Vector2u Game::getFieldSize() {
	return sf::Vector2u(this->width, this->height);
}