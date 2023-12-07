#pragma once
#include <SFML/Graphics.hpp>
#include <utility>
#include "TextureManager.h"

class Fruit {
	sf::Vector2u v;
public:
	Fruit(int x, int y);
	Fruit(std::pair<int, int> p);
	void draw(sf::RenderWindow, int, int);
	void setPosition(std::pair<uint16_t, uint16_t>);
	friend bool operator<(const Fruit& f1, const Fruit& f2);
};