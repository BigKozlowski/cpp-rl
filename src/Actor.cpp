#include "./Actor.hpp"
#include <iostream>

void Actor::act(World& world) 
{
    Command cmd = controller_->decide(world, *this);
    switch(cmd) {
        case Command::MoveEast: {
            position_.x++;
            break;
        }
        case Command::MoveWest: {
            position_.x--;
            break;
        }
        case Command::MoveNorth: {
            position_.y--;
            break;
        }
        case Command::MoveSouth: {
            position_.y++;
            break;
        }
        case Command::None:
        case Command::Wait:
        case Command::Interact:
            break;
    }
}

Actor::Actor(
    Position position,
    Renderable renderable,
    Health health,
    Attack attack,
    Defense defense,
    std::unique_ptr<ActorController> controller
)
    : position_(position),
      renderable_(renderable),
      health_(health),
      attack_(attack),
      defense_(defense),
      controller_(std::move(controller))
{
}

GridPosition Actor::getPosition() const {
    return GridPosition{.x = position_.x, .y = position_.y};
}

std::string Actor::getTextureName() const {
    return renderable_.texture_name;
}