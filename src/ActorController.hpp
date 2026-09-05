#pragma once

#include "Command.hpp"

class World;
class Actor;

class ActorController {
public:
    virtual ~ActorController() = default;
    virtual Command decide(const World& world, const Actor& actor) = 0;
};