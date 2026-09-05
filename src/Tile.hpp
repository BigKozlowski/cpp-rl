#pragma once

enum class TileType {
    Floor,
    Wall,
    Door,
    StairsUp,
    StairsDown
};

struct Tile {
    TileType type;
    bool explored = false;
};