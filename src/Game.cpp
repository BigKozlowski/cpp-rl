#include "./Game.hpp"
#include "AiController.hpp"
#include "PlayerController.hpp"

void Game::render() {
    renderer_.render(world_);
}

void Game::init() {
    Actor player = Actor(
        Position{10, 20},
        Renderable{"smiley"},
        Health{.current = 100, .maximum = 100},
        Attack{0},
        Defense{0},
        std::make_unique<PlayerController>(input_)
    );
    world_.addActor(std::move(player));

    Actor spider = Actor(
        Position{15, 27},
        Renderable{"spider"},
        Health{.current = 100, .maximum = 100},
        Attack{0},
        Defense{0},
        std::make_unique<AiController>()
    );
    world_.addActor(std::move(spider));

}

void Game::update() {
    input_.update();
    world_.update();
}

void Game::step() {
    update();
    render();
}