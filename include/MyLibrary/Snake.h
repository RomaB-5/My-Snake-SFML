#pragma once 
#include "Personal2DVector.h"
#include <list>
#include "SFML/Graphics.hpp"

class Snake {
private:
	std::list<P2DVec> body;
	P2DVec direction;

public:
	Snake(int n, int m);

	std::list<P2DVec>::iterator head() { return this->body.begin(); }

	void setDirection(int8_t i, int8_t j);

	void grow(void);
	
	void move(void);

	void draw(sf::RenderWindow&, short, short);
};