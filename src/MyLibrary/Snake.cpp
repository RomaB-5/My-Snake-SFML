#include "../../include/MyLibrary/Snake.h"
#include <algorithm>
#include "../../include/MyLibrary/TextureManager.h"

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

void Snake::draw(sf::RenderWindow& window, uint16_t n, uint16_t m) {
	// should be loaded in Game constructor ?
	TextureManager& textureManager = TextureManager::getInstance();
	textureManager.loadTexture("snake-green", "assets/textures/snake-green.png");

	for (auto cell : body) {
		sf::Sprite sprite;
		sprite.setTexture(textureManager.getTexture("snake-green"));
		sprite.setPosition(cell.x / (1. * n) * window.getSize().x, cell.y / (1. * m) * window.getSize().y);
		
		auto xScale = sprite.getGlobalBounds().width / (window.getSize().x / n);
		auto yScale = sprite.getGlobalBounds().height / (window.getSize().y / m);
		sprite.setScale(xScale, yScale);
		window.draw(sprite);
	}

}