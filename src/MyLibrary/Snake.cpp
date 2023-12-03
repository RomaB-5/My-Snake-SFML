#include "../../include/MyLibrary/Snake.h"

void Snake::grow() {
	this->body.push_back(P2DVec(
		this->body.end()->get_x(),
		this->body.end()->get_y()
	));
}

void Snake::move() {
	int8_t x = this->direction.get_x();
	int8_t y = this->direction.get_y();
}