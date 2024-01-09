#include <SFML/Graphics.hpp>

class SpriteNormalizer
{
public:
	static void normalize(sf::Sprite& sprite, sf::RenderWindow& window, uint16_t xCells, uint16_t yCells);
};