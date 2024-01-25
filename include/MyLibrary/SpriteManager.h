#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class SpriteManager {
public:
    // Singleton pattern to ensure a single instance of the manager
    static SpriteManager& getInstance();

    // Load a texture from a file
    bool addSprite(const std::string textureName, const std::string spriteName);

    // Get a texture by name
    void getSprite(const std::string textureName, sf::Sprite& sprite);

private:
    // Private constructor to enforce singleton pattern
    SpriteManager() = default;

    // Private destructor to enforce singleton pattern
    ~SpriteManager() = default;

    // Copy constructor is deleted to prevent cloning
    SpriteManager(const SpriteManager&) = delete;

    // Assignment operator is deleted to prevent assignment
    SpriteManager& operator=(const SpriteManager&) = delete;

    // Map to store loaded textures
    std::unordered_map<std::string, sf::Sprite> sprites;
};