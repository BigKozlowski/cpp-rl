#pragma once

#include <raylib.h>

#include "World.hpp"
#include "TextureManager.hpp"

class Renderer {
private:
    void renderMap(const Map& map);
    void renderItems(const std::vector<Item>& items);
    void renderActors(const std::vector<Actor>& actors);
    void renderTile(Tile tile, GridPosition position);
    TextureManager textures_;
public:
    Renderer();
    void render(const World& world);
};