#pragma once

#include <string>
#include <unordered_map>

#include <raylib.h>

#include "TextureResource.hpp"

class TextureManager {
public:
    const Texture2D& get(const std::string& name) const {
        return textures.at(name).get();
    }

    void load(const std::string& name, const std::string& path) {
        textures.emplace(
            name,
            TextureResource{LoadTexture(path.c_str())}
        );
    }

    bool has(const std::string& name) const {
        return textures.contains(name);
    }

private:
    std::unordered_map<std::string, TextureResource> textures;
};