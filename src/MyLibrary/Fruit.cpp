#include "../../include/MyLibrary/Fruit.h"
#include "../../include/util/SpriteNormalizer.h"

// constructor
Fruit::Fruit(int x, int y) {
	this->setPosition(std::pair<int, int>(x, y));
}

Fruit::Fruit(std::pair<int,int> p) {
	this->setPosition(p);
}

void Fruit::draw(sf::RenderWindow &window, int xCells, int yCells) {

	sf::Sprite sprite;
	sprite.setTexture(TextureManager::getInstance().getTexture("fruit"));

	auto windowWidth = window.getSize().x;
	auto windowHeight = window.getSize().y;

	//sf::FloatRect visibleArea(0, 0, windowWidth, windowHeight);
	//window.setView(sf::View(visibleArea));

	sprite.setPosition(sf::Vector2f(
		1. * this->v.x * windowWidth / xCells, 1. * this->v.y * windowHeight / yCells
	));

	SpriteNormalizer::normalize(sprite, window, xCells, yCells);

	window.draw(sprite);
}

void Fruit::setPosition(std::pair<uint16_t, uint16_t> p) {
	this->v.x = p.first;
	this->v.y = p.second;
}

bool operator<(const Fruit& f1, const Fruit& f2) {
	return std::pair<int, int>(f1.v.x, f1.v.y) < std::pair<int, int>(f2.v.x, f2.v.y);
}