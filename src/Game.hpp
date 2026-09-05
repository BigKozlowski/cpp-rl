#pragma once
#include "Renderer.hpp"
#include "Input.hpp"

// #include "./World.hpp"

class Game {
public:
    void init();
    void step();
    
    private:
    int x;
    int y;
    // void handleInput();
    void update();
    void render();

    World world_;
    Renderer renderer_;
    Input input_;
};