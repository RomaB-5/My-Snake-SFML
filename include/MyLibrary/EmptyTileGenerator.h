#pragma once
#include <set>
#include <utility>
#include <SFML/Graphics.hpp>

class EmptyTileGenerator {
public:
    // Singleton pattern to ensure a single instance of the manager
    static EmptyTileGenerator& getInstance();

    std::pair<int, int> getEmptyTile();

    void pushNewTile(sf::Vector2u);
    void pushNewTile(std::pair<uint16_t, uint16_t>);

private:
    std::set<std::pair<int, int>> EmptyTiles;

    // Private constructor to enforce singleton pattern
    EmptyTileGenerator() = default;

    // Private destructor to enforce singleton pattern
    ~EmptyTileGenerator() = default;

    // Copy constructor is deleted to prevent cloning
    EmptyTileGenerator(const EmptyTileGenerator&) = delete;

    // Assignment operator is deleted to prevent assignment
    EmptyTileGenerator& operator=(const EmptyTileGenerator&) = delete;
};