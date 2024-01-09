#include "../../include/MyLibrary/Snake.h"
#include <algorithm>
#include "../../include/MyLibrary/TextureManager.h"
#include "../../include/MyLibrary/EmptyTileGenerator.h"
#include "../../include/util/SpriteNormalizer.h"

Snake::Snake() {
	// randomly spawn the head on a field

	std::pair<uint16_t, uint16_t> p = EmptyTileGenerator::getInstance().getEmptyTile();
	this->body.push_back(sf::Vector2i(p.first, p.second));
}

void Snake::setDirection(Snake::Direction direction) {
	switch (direction) {
	case Snake::Direction::UP:
		if (this->direction.y != 1) {
			this->direction.x = 0;
			this->direction.y = -1;
		}
		break;
	case Snake::Direction::DOWN:
		if (this->direction.y != -1) {
			this->direction.x = 0;
			this->direction.y = 1;
		}
		break;
	case Snake::Direction::LEFT:
		if (this->direction.x != 1) {
			this->direction.x = -1;
			this->direction.y = 0;
		}
		break;
	case Snake::Direction::RIGHT:
		if (this->direction.x != -1) {
			this->direction.x = 1;
			this->direction.y = 0;
		}
		break;
	}

}

void Snake::grow() {
	// two snake segments are at the same position for a moment
	this->body.push_back(sf::Vector2i(
		prev(this->body.end())->x,
		prev(this->body.end())->y
	));
	
}

void Snake::move() {
	int8_t dx = this->direction.x;
	int8_t dy = this->direction.y;

	// free the previous tale tile and add it to the empty tiles set
	if ( ( this->body.size() > 1 && 
		*prev(this->body.end()) != *prev(prev(this->body.end())) ) || this->body.size() == 1) {

		EmptyTileGenerator::getInstance().pushNewTile(
			sf::Vector2i(
				prev(this->body.end())->x,
				prev(this->body.end())->y
			)
		);
	}



	// body movement
	for (auto it = prev(this->body.end()); it != this->body.begin(); it--) {
		it->x = (prev(it)->x);
		it->y = (prev(it)->y);
	}

	// head movement
	this->head()->x = (this->head()->x + dx);
	this->head()->y = (this->head()->y + dy);
	

	// take the new head tile and remove it from the empty tiles set
	EmptyTileGenerator::getInstance().EraseTile(
		sf::Vector2i(
			this->head()->x,
			this->head()->y
		)
	);
}

void Snake::draw(sf::RenderWindow& window, uint16_t xCells, uint16_t yCells) {
	
	TextureManager& textureManager = TextureManager::getInstance();

	for (auto cell = next(body.begin()); cell != body.end(); cell++) {

		sf::Sprite sprite;
		sprite.setTexture(textureManager.getTexture("snake-green"));
		sprite.setPosition(cell->x / (1. * xCells) * window.getSize().x, cell->y / (1. * yCells) * window.getSize().y);
		
		SpriteNormalizer::normalize(sprite, window, xCells, yCells);

		window.draw(sprite);
	}

	// draw head
	sf::Sprite headSprite;
	auto head = this->head();
	headSprite.setTexture(textureManager.getTexture("snake-yellow-head"));
	headSprite.setPosition(head->x / (1. * xCells) * window.getSize().x, head->y / (1. * yCells) * window.getSize().y);
	SpriteNormalizer::normalize(headSprite, window, xCells, yCells);
	window.draw(headSprite);

}