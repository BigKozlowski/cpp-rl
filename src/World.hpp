#pragma once

#include <vector>

#include "./Map.hpp"
#include "./Actor.hpp"
#include "./Item.hpp"
#include "Command.hpp"

class World {
public:
    World();
    void setMap(Map map);
    void addActor(Actor actor);
    void addItem(Item item);

    const Map& map() const;

    const std::vector<Actor>& actors() const;
    const std::vector<Item>& items() const;

    void update();

private:
    Map map_;
    std::vector<Actor> actors_;
    std::vector<Item> items_;
};