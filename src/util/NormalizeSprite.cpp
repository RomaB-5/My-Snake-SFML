#include "../../include/util/SpriteNormalizer.h"

void SpriteNormalizer::normalize(sf::Sprite& sprite, sf::RenderWindow& window, uint16_t xCells, uint16_t yCells) {
	auto currentWidth = sprite.getGlobalBounds().getSize().x;
	auto currentHeight = sprite.getGlobalBounds().getSize().y;

	auto windowWidth = window.getSize().x;
	auto windowHeight = window.getSize().y;

	auto scaleX = (1. * windowWidth / xCells) / currentWidth;
	auto scaleY = (1. * windowHeight / yCells) / currentHeight;

	sprite.setScale(scaleX, scaleY);
}