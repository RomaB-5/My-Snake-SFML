# pragma once 
#include <SFML/Graphics.hpp>
#include <list>

class Snake {
private:
	std::list<sf::Vector2i> body;
	sf::Vector2i direction;
public:
	std::list<sf::Vector2i>::iterator head() { return this->body.begin(); }

	void grow(void);
	
	void move(void);
};