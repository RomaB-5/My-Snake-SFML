#pragma once
#include <SFML/Graphics.hpp>
#include <utility>

class Fruit {
	sf::Vector2u v;
public:
	Fruit(int x, int y);
	Fruit(std::pair<int, int> p);
	void draw(void);
	void setPosition(std::pair<uint16_t, uint16_t>);
	friend bool operator<(const Fruit& f1, const Fruit& f2);
};