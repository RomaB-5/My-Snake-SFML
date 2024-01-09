# pragma once 
#include <SFML/Graphics.hpp>
#include <list>
#include "EmptyTileGenerator.h"

class Snake {
private:
	std::list<sf::Vector2i> body;
	sf::Vector2i direction;

public:
	Snake();

	std::list<sf::Vector2i>::iterator head() { return this->body.begin(); }
	std::list<sf::Vector2i>::iterator tail() { return prev(this->body.end()); }

	enum class Direction {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	// increases snake size by one 
	void grow(void);
	
	// moves each body cell on the place of the following cell
	// than moves head in the (direction.x, direction.y) direction.
	void move(void);

	void draw(sf::RenderWindow&, uint16_t, uint16_t);

	void setDirection(Snake::Direction direction);
	sf::Vector2i getDirection() { return this->direction; }

	uint16_t getLength() { return this->body.size(); }
};
