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
    std::set<std::pair<uint16_t, uint16_t>> EmptyTiles;

    EmptyTileGenerator() = default;

    ~EmptyTileGenerator() = default;

    EmptyTileGenerator(const EmptyTileGenerator&) = delete;

    EmptyTileGenerator& operator=(const EmptyTileGenerator&) = delete;
};