#include "../../include/MyLibrary/TextureManager.h"

TextureManager& TextureManager::getInstance() {
    static TextureManager instance;
    return instance;
}

bool TextureManager::loadTexture(const std::string& textureName, const std::string& filePath) {
    sf::Texture texture;
    if (texture.loadFromFile(filePath)) {
        textures[textureName] = texture;
        return true;
    }
    return false;
}

sf::Texture& TextureManager::getTexture(const std::string& textureName) {
    // If the texture exists in the map, return a reference to it
    // Otherwise, return a placeholder texture 
    return textures.at(textureName);
}