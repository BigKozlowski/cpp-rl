#include "./World.hpp"

World::World()
    : map_(50, 30)
{
    map_ = Map("../assets/test.map");
}

void World::setMap(Map map)
{
    map_ = std::move(map);
}

const Map& World::map() const 
{
    return map_;
}

const std::vector<Actor>& World::actors() const
{
    return actors_;
}

const std::vector<Item>& World::items() const
{
    return items_;
}

void World::update() 
{
    for (auto& actor : actors_) {
        actor.act(*this);
    }
}

void World::addActor(Actor a) 
{
    actors_.push_back(std::move(a));
}

