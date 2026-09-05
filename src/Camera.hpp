#pragma once

#include "Actor.hpp"

class Camera {
public:
    void follow(const Actor* actor);
    void clearTarget();

    void update();

private:
    const Actor* target_ = nullptr;
};