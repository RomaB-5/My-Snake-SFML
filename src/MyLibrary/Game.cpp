#include "../../include/MyLibrary/Game.h"

Game::Game(int n, int m) {
	this->dim = new P2DVec(n, m);
	this->snake = new Snake(n,m);
	this->fg = new FruitGenerator(P2DVec(this->snake->head()->get_x(), this->snake->head()->get_y()), n, m);
}

Game::~Game() {
	delete dim;
	delete snake;
	delete fg;
}

void Game::draw(sf::RenderWindow& window) {
	this->snake->draw(window, this->dim->get_x(), this->dim->get_y());
}

void Game::update() {
	this->snake->move(this->fg);
}

void Game::setSnakeDirection(int8_t dx, int8_t dy) {
	this->snake->setDirection(dx, dy);
}