#include "../../include/MyLibrary/EmptyTileGenerator.h"
#include <random>
#include <algorithm>

EmptyTileGenerator& EmptyTileGenerator::getInstance() {
	static EmptyTileGenerator instance;
	return instance;
}

// sets the empty field at the beginning of the game
void EmptyTileGenerator::setField(uint16_t n, uint16_t m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			this->EmptyTiles.insert(std::pair<uint16_t, uint16_t>(i,j));
		}
	}
}

// returns a random empty tile
std::pair<int, int> EmptyTileGenerator::getEmptyTile() {
	
	// TODO: throw an exception
	if (!EmptyTiles.size());

	// TODO: use a better random generator 
	// TODO: make more efficient algorithm
	uint16_t offset = std::rand() % this->EmptyTiles.size();
	auto it = this->EmptyTiles.begin();
	std::advance(it, offset);
	
	auto res = *it;
	EmptyTiles.erase(res);

	return res;
}

// adds a new empty tile
void EmptyTileGenerator::pushNewTile(sf::Vector2u v) {
	this->EmptyTiles.insert(std::pair<uint16_t, uint16_t>(v.x, v.y));
}

void EmptyTileGenerator::pushNewTile(std::pair<uint16_t, uint16_t> p) {
	this->EmptyTiles.insert(p);
}


// erases a tile from the set (it is not empty anymore)
bool EmptyTileGenerator::EraseTile(sf::Vector2u v) {
	auto p = std::pair<uint16_t, uint16_t>(v.x, v.y);

	if (this->EmptyTiles.find(p) == this->EmptyTiles.end()) {
		return false;
	}

	this->EmptyTiles.erase(p);
	return true;
}

bool EmptyTileGenerator::EraseTile(std::pair<uint16_t, uint16_t> p) {

	if (this->EmptyTiles.find(p) == this->EmptyTiles.end()) {
		return false;
	}

	this->EmptyTiles.erase(p);
	return true;
}