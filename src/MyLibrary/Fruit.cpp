#include "../../include/MyLibrary/Fruit.h"

Fruit::Fruit(int x, int y) {
	this->setPosition(std::pair<int, int>(x, y));
}

Fruit::Fruit(std::pair<int,int> p) {
	this->setPosition(p);
}

void Fruit::draw() {

}

void Fruit::setPosition(std::pair<uint16_t, uint16_t> p) {
	this->v.x = p.first;
	this->v.y = p.second;
}

bool operator<(const Fruit& f1, const Fruit& f2) {
	return std::pair<int, int>(f1.v.x, f1.v.y) < std::pair<int, int>(f2.v.x, f2.v.y);
}