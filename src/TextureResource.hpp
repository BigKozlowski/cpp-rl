#pragma once

#include <raylib.h>

class TextureResource {
public:
    explicit TextureResource(Texture2D texture)
        : texture(texture) {}

    ~TextureResource() {
        if (texture.id != 0)
            UnloadTexture(texture);
    }

    TextureResource(const TextureResource&) = delete;
    TextureResource& operator=(const TextureResource&) = delete;

    TextureResource(TextureResource&& other) noexcept
        : texture(other.texture) {
        other.texture = {};
    }

    TextureResource& operator=(TextureResource&& other) noexcept {
        if (this != &other) {
            if (texture.id != 0)
                UnloadTexture(texture);

            texture = other.texture;
            other.texture = {};
        }

        return *this;
    }

    const Texture2D& get() const {
        return texture;
    }

private:
    Texture2D texture{};
};