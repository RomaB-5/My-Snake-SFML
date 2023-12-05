#pragma once
#include <SFML/Graphics.hpp>
#include <utility>

class Fruit {
	sf::Vector2u v;
public:
	void draw(void);
	void setPosition(std::pair<uint16_t, uint16_t>);

};