#include "./Renderer.hpp"

#include <iostream>

Renderer::Renderer() {
    textures_.load("wall", "../assets/tile_0040.png");
    textures_.load("smiley", "../assets/tile_0087.png");
    textures_.load("floor", "../assets/tile_0000.png");
    textures_.load("door", "../assets/tile_0045.png");
    textures_.load("spider", "../assets/tile_0122.png");
}

void Renderer::render(const World& world) {
    ClearBackground(Color{.r = 0, .g = 0, .b = 0, .a = 255});
    BeginDrawing();
    renderMap(world.map());
    renderItems(world.items());
    renderActors(world.actors());
    EndDrawing();
}

void Renderer::renderMap(const Map& map) {
    std::cout << map.height() << " " << map.width() << std::endl;
    for(int y = 0; y < map.height(); y++) {
        for(int x = 0; x < map.width(); x++) {
            Tile tile = map.tile({.x = x, .y = y});
            if(tile.explored) {
                renderTile(tile, {.x = x, .y = y});
            }
        }
    }
}

void Renderer::renderTile(Tile tile, GridPosition position) {
    std::string textureName;
    switch(tile.type) {
        case TileType::Floor: {
            textureName = "floor";
            break;
        };
        case TileType::Wall: {
            textureName = "wall";
            break;
        };
        case TileType::Door: {
            textureName = "door";
            break;
        };
        case TileType::StairsDown: {
            break;
        };
        case TileType::StairsUp: {
            break;
        };
    }

    auto& texture = textures_.get(textureName);
    DrawTexture(texture, position.x * 16, position.y * 16, WHITE);
}

void Renderer::renderActors(const std::vector<Actor>& actors) {
    for(const Actor& actor : actors) {
        auto textureName = actor.getTextureName();
        auto& texture = textures_.get(textureName);
        GridPosition position = actor.getPosition();
        DrawTexture(texture, position.x * 16, position.y * 16, WHITE);
    }
}

void Renderer::renderItems(const std::vector<Item>& items) {

}