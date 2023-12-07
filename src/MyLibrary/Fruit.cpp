#include "../../include/MyLibrary/Fruit.h"

void Fruit::draw() {

}

void Fruit::setPosition(std::pair<uint16_t, uint16_t> p) {
	this->v.x = p.first;
	this->v.y = p.second;
}