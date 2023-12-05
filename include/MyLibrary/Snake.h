# pragma once 
#include <SFML/Graphics.hpp>
#include <list>

class Snake {
private:
	std::list<sf::Vector2i> body;
	sf::Vector2i direction;

public:
	std::list<sf::Vector2i>::iterator head() { return this->body.begin(); }

	// increases snake size by one 
	void grow(void);
	
	// moves each body cell on the place of the following cell
	// than moves head in the (direction.x, direction.y) direction.
	void move(void);

	void draw(sf::RenderWindow&, uint16_t, uint16_t);
};