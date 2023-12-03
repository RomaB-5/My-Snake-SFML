#include "../../include/MyLibrary/Snake.h"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <random>

Snake::Snake(int n, int m) {
	srand(time(0));
	this->body.push_back(P2DVec(rand() % n, rand() % m));
}

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

void Snake::draw(sf::RenderWindow &window, short n, short m) {
	unsigned int w = window.getSize().x; //width
	unsigned int h = window.getSize().y; //height
	unsigned int cellHeight = h / n;
	unsigned int cellWidth = w / m;

	for (auto i : this->body) {
		sf::RectangleShape rectangle(sf::Vector2f(cellWidth, cellHeight));
		rectangle.setFillColor(sf::Color(0, 120, 40));
		rectangle.setPosition(cellWidth * i.get_x(), cellHeight * i.get_y());
		window.draw(rectangle);
	}
}