#pragma once
#include "Snake.h"
#include <SFML/Graphics.hpp>

class Game {
	Snake* snake;
	uint8_t height = 10;
	uint8_t width = 10;
public:
	Game();
	sf::Vector2u getFieldSize();
	void draw();
	void update();
};