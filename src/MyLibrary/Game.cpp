#include "../../include/MyLibrary/Game.h"
#include <iostream>

// initializes the game
Game::Game() {

	TextureManager::getInstance().loadTexture("fruit", "D:\\Університет\\SFML\\My-Snake-SFML\\assets\\textures\\apple-red.png");
	TextureManager::getInstance().loadTexture("snake-green", "D:\\Університет\\SFML\\My-Snake-SFML\\assets\\textures\\snake-green.png");
	TextureManager::getInstance().loadTexture("snake-yellow-head", "D:\\Університет\\SFML\\My-Snake-SFML\\assets\\textures\\snake-yellow-head.png");
	// all tiles are accesable
	EmptyTileGenerator &ETG = EmptyTileGenerator::getInstance();
	ETG.setField(this->width, this->height);

	// initializes snake by placing its head on a map
	this->snake = new Snake();

	// initializes froots
	for (int i = 0; i < this->fruitNum; i++) {
		this->fruits.insert(Fruit(ETG.getEmptyTile()));
	}
	std::cout << "Numbet of free cels: " << ETG.size() << "\n";
}

void Game::draw(sf::RenderWindow &window, int xCells, int yCells) {
	for (auto fruit : this->fruits) {
		fruit.draw(window, xCells, yCells);
	}

	snake->draw(window, xCells, yCells);
}

void Game::update() {
	auto& ETG = EmptyTileGenerator::getInstance();

	sf::Vector2i nextHeadPos = *this->snake->head() + 
		sf::Vector2i(this->snake->getDirection().x, this->snake->getDirection().y);

	if (!ETG.isEmpty(nextHeadPos) &&
		this->fruits.find(Fruit(nextHeadPos.x, nextHeadPos.y)) == this->fruits.end() &&
		(*this->snake->tail() != nextHeadPos)
		) {
		//std::cout << "Numbet of free cels: " << ETG.size() << "\n";
		this->isGameOver = true;
		return;
	}


	this->snake->move();


	// check if snake is alive
	if (this->snake->head()->x < 0 || this->snake->head()->x >= this->width ||
		this->snake->head()->y < 0 || this->snake->head()->y >= this->height) {
		this->isGameOver = true;
		return;
	}


	// check if ate a fruit
	auto head = this->snake->head();
	if (this->fruits.find(Fruit(head->x, head->y)) != this->fruits.end()) {
		// snake grows
		snake->grow();
		// remove fruit from set
		EmptyTileGenerator::getInstance().EraseTile(sf::Vector2i(head->x, head->y));
		// add new fruit
		this->fruits.insert(Fruit(ETG.getEmptyTile()));
		// erase old fruit
		this->fruits.erase(Fruit(head->x, head->y));
	}

}

sf::Vector2u Game::getFieldSize() {
	return sf::Vector2u(this->width, this->height);
}

bool Game::isOver() {
	return this->isGameOver;
}