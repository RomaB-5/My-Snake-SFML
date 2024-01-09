#pragma once
#include <set>
#include "Snake.h"
#include "Fruit.h"
#include "EmptyTileGenerator.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>

class Game {
public:
	Snake* snake;

private:
	uint8_t height = 50;
	uint8_t width = 50;
	uint8_t fruitNum = 1;
	std::set<Fruit> fruits;
	bool isGameOver = false;

public:
	Game();
	sf::Vector2u getFieldSize();
	bool isOver();
	void draw(sf::RenderWindow& window, int xCells, int yCells);
	void update();
};