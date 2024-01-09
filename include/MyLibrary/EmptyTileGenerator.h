#pragma once
#include <set>
#include <utility>
#include <SFML/Graphics.hpp>

class EmptyTileGenerator {
public:
    // Singleton pattern to ensure a single instance of the manager
    static EmptyTileGenerator& getInstance();

    std::pair<int, int> getEmptyTile();

    // adds tile when it becomes empty
    void pushNewTile(sf::Vector2i);
    void pushNewTile(std::pair<uint16_t, uint16_t>);

    // erases tile when it is not empty
    bool EraseTile(sf::Vector2i);
    bool EraseTile(std::pair<uint16_t, uint16_t>);

    // fills the field at the start of the game
    void setField(uint16_t, uint16_t);

    bool isEmpty(sf::Vector2i);

    int size();

private:
    std::set<std::pair<uint16_t, uint16_t>> EmptyTiles;

    EmptyTileGenerator() = default;

    ~EmptyTileGenerator() = default;

    EmptyTileGenerator(const EmptyTileGenerator&) = delete;

    EmptyTileGenerator& operator=(const EmptyTileGenerator&) = delete;
};