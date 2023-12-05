#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class TextureManager {
public:
    // Singleton pattern to ensure a single instance of the manager
    static TextureManager& getInstance();

    // Load a texture from a file
    bool loadTexture(const std::string& textureName, const std::string& filePath);

    // Get a texture by name
    sf::Texture& getTexture(const std::string& textureName);

private:
    // Private constructor to enforce singleton pattern
    TextureManager() = default;

    // Private destructor to enforce singleton pattern
    ~TextureManager() = default;

    // Copy constructor is deleted to prevent cloning
    TextureManager(const TextureManager&) = delete;

    // Assignment operator is deleted to prevent assignment
    TextureManager& operator=(const TextureManager&) = delete;

    // Map to store loaded textures
    std::unordered_map<std::string, sf::Texture> textures;
};