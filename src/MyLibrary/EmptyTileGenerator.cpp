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