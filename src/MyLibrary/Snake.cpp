#include "../../include/MyLibrary/Snake.h"
#include <algorithm>
#include "../../include/MyLibrary/TextureManager.h"
#include "../../include/util/SpriteNormalizer.h"

Snake::Snake() {
	// randomly spawn the head on a field

	std::pair<uint16_t, uint16_t> p = EmptyTileGenerator::getInstance().getEmptyTile();
	this->body.push_back(sf::Vector2i(p.first, p.second));
}

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

void Snake::draw(sf::RenderWindow& window, uint16_t xCells, uint16_t yCells) {
	// should be loaded in Game constructor ?
	TextureManager& textureManager = TextureManager::getInstance();

	for (auto cell : body) {
		// TODO: normalize sprite size in an external function?
		sf::Sprite sprite;
		sprite.setTexture(textureManager.getTexture("snake-green"));
		sprite.setPosition(cell.x / (1. * xCells) * window.getSize().x, cell.y / (1. * yCells) * window.getSize().y);
		
		SpriteNormalizer::normalize(sprite, window, xCells, yCells);

		window.draw(sprite);
	}

}