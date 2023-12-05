#pragma once
#include <set>
#include <utility>

class EmptyTileGenerator() {
public:
    // Singleton pattern to ensure a single instance of the manager
    static EmptyTileGenerator& getInstance();

private:
    set<pair<int, int>> EmptyTiles;

    // Private constructor to enforce singleton pattern
    EmptyTileGenerator() = default;

    // Private destructor to enforce singleton pattern
    ~EmptyTileGenerator() = default;

    // Copy constructor is deleted to prevent cloning
    EmptyTileGenerator(const EmptyTileGenerator&) = delete;

    // Assignment operator is deleted to prevent assignment
    EmptyTileGenerator& operator=(const EmptyTileGenerator&) = delete;
};