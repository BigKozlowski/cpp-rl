#pragma once
#include <memory>


#include "./Components.hpp"
#include "./ActorController.hpp"
#include "GridPosition.hpp"

class Actor {
    Position position_;
    Renderable renderable_;
    Health health_;
    Attack attack_;
    Defense defense_;
    std::unique_ptr<ActorController> controller_;
public:
    Actor(
        Position position,
        Renderable renderable,
        Health health,
        Attack attack,
        Defense defense,
        std::unique_ptr<ActorController> controller
    );
    void act(World& world);
    GridPosition getPosition() const;
    std::string getTextureName() const;
};