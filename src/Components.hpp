#pragma once

#include <string>

struct Health {
    int current;
    int maximum;
};

struct Attack {
    int damage;
};

struct Defense {
    int armor;
};

struct Position {
    int x;
    int y;
};

struct Renderable {
    std::string texture_name;
};