#include "../../include/MyLibrary/FruitGenerator.h"

FruitGenerator::FruitGenerator(P2DVec head, int n, int m) {

	// the set contains all cell except for the cell, where head of a snake is placed
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			this->freeCells.insert(P2DVec(i, j));
		}
	}
	
	this->freeCells.erase(head);
}

void FruitGenerator::addCell(P2DVec cell) {
	this->freeCells.insert(cell);
}

void FruitGenerator::removeCell(P2DVec cell) {
	this->freeCells.erase(cell);
}

P2DVec FruitGenerator::generate() {
	srand(time(0));

	short index = rand() % this->freeCells.size();
	auto it = this->freeCells.begin();

	advance(it, index);
	auto res = *it;
	freeCells.erase(*it);

	return res;

}