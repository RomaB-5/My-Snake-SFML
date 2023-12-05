#include "../../include/MyLibrary/EmptyTileGenerator.h"
#include <random>
#include <algorithm>

std::pair<int, int> EmptyTileGenerator::getEmptyTile() {

	if (!EmptyTiles.size());

	uint16_t offset = std::rand() % this->EmptyTiles.size();
	auto it = this->EmptyTiles.begin();
	std::advance(it, offset);
	
	auto res = *it;
	EmptyTiles.erase(res);

	return res;
}

void EmptyTileGenerator::pushNewTile(sf::Vector2u v) {
	this->EmptyTiles.insert(std::pair<uint16_t, uint16_t>(v.x, v.y));
}

void EmptyTileGenerator::pushNewTile(std::pair<uint16_t, uint16_t> p) {
	this->EmptyTiles.insert(p);
}

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