#include "../../include/MyLibrary/Snake.h"
#include <algorithm>

void Snake::grow() {
	this->body.push_back(P2DVec(
		this->body.end()->get_x(),
		this->body.end()->get_y()
	));
}

void Snake::move() {
	int8_t dx = this->direction.get_x();
	int8_t dy = this->direction.get_y();

	// body movement
	for (auto it = ++this->body.begin(); it != this->body.end(); it++) {
		it->set_x(prev(it)->get_x());
		it->set_y(prev(it)->get_y());
	}

	// head movement
	this->head()->set_x(this->head()->get_x() + dx);
	this->head()->set_y(this->head()->get_y() + dy);
}