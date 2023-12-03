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