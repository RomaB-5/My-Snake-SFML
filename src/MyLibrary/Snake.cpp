#include "../../include/MyLibrary/Snake.h"
#include <algorithm>

void Snake::grow() {
	this->body.push_back(sf::Vector2i(
		this->body.end()->x,
		this->body.end()->y
	));
}

void Snake::move() {
	int8_t dx = this->direction.x;
	int8_t dy = this->direction.y;

	// body movement
	for (auto it = ++this->body.begin(); it != this->body.end(); it++) {
		it->x = (prev(it)->x);
		it->y = (prev(it)->y);
	}

	// head movement
	this->head()->x = (this->head()->x + dx);
	this->head()->y = (this->head()->y + dy);
}