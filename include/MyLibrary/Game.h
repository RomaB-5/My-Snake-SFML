#pragma once
#include <set>
#include "Snake.h"
#include "Fruit.h"
#include "EmptyTileGenerator.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>

class Game {
	Snake* snake;
	uint8_t height = 15;
	uint8_t width = 15;
	uint8_t fruitNum = 3;
	std::set<Fruit> fruits;

public:
	Game();
	sf::Vector2u getFieldSize();
	void draw(sf::RenderWindow& window, int xCells, int yCells);
	void update();
};