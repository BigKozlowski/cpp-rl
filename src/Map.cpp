#include "./Map.hpp"

#include <fstream>
#include <stdexcept>
#include <string>

Map::Map(int width, int height)
    : width_(width),
      height_(height),
      tiles_(width * height)
{
    for (auto& tile : tiles_) {
        tile.explored = true;
        tile.type = TileType::Floor;
    }
}

Map::Map(const std::string& path) {
    std::ifstream file(path);

    if (!file) {
        throw std::runtime_error("Failed to open map: " + path);
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        // Убираем \r для Windows-файлов
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        if (!line.empty()) {
            lines.push_back(line);
        }
    }

    if (lines.empty()) {
        throw std::runtime_error("Map is empty: " + path);
    }

    width_ = static_cast<int>(lines[0].size());
    height_ = static_cast<int>(lines.size());

    for (const auto& line : lines) {
        if (static_cast<int>(line.size()) != width_) {
            throw std::runtime_error("Map has inconsistent row width: " + path);
        }
    }

    tiles_.reserve(width_ * height_);

    for (const auto& line : lines) {
        for (char c : line) {
            Tile tile;

            tile.explored = true;

            switch (c) {
                case '.':
                    tile.type = TileType::Floor;
                    break;

                case '#':
                    tile.type = TileType::Wall;
                    break;
                
                case 'D':
                    tile.type = TileType::Door;
                    break;

                default:
                    throw std::runtime_error(
                        "Unknown tile character in map: " + std::string(1, c)
                    );
            }

            tiles_.push_back(tile);
        }
    }
}

int Map::height() const {
    return height_;
}

int Map::width() const {
    return width_;
}

const Tile& Map::tile(GridPosition position) const {
    return tiles_[position.y * width_ + position.x];
}