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