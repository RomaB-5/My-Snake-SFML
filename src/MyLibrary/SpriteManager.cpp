#include "../../include/MyLibrary/SpriteManager.h"
#include "../../include/MyLibrary/TextureManager.h"

SpriteManager& SpriteManager::getInstance() {
	static SpriteManager instance;
	return instance;
}

bool SpriteManager::addSprite(const std::string spriteName, const std::string textureName) {
	sf::Sprite sprite;
	auto &texture = TextureManager::getInstance().getTexture(textureName);
	sprite.setTexture(texture);
	sprites[spriteName] = sprite;
	return true;
}

void SpriteManager::getSprite(const std::string spriteName, sf::Sprite& sprite) {
	if (sprites.find(spriteName) != sprites.end()) {
		sprite = sprites.at(spriteName);
	}
}