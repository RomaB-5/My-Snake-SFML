#pragma once

#include "Snake.h"
#include "FruitGenerator.h"
#include "Personal2DVector.h"
#include <SFML/Graphics.hpp>
#include <random>

class Game {
	Snake *snake;
	FruitGenerator *fg;
	P2DVec *dim;

public:
	Game(int n = 10, int m = 10);
	~Game();

	void setSnakeDirection(int8_t dx, int8_t dy);
	void draw(sf::RenderWindow&);
	void update();
};