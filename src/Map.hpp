#pragma once

#include <string>
#include <vector>

#include "GridPosition.hpp"
#include "Tile.hpp"

class Map {
public:
    Map(int width, int height);
    explicit Map(const std::string& path);

    int width() const;
    int height() const;

    const Tile& tile(GridPosition position) const;

private:
    int width_;
    int height_;
    std::vector<Tile> tiles_;
};