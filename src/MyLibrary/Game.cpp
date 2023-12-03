#include "../../include/MyLibrary/Game.h"

Game::Game(int n = 10, int m = 10) {
	this->dim = new P2DVec(n, m);
	this->snake = new Snake(n,m);
	this->fg = new FruitGenerator(P2DVec(this->snake->head()->get_x(), this->snake->head()->get_y()));
}

Game::~Game() {
	delete dim;
	delete snake;
	delete fg;
}