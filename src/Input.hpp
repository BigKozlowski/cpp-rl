#pragma once
#include "Command.hpp"

class Input {
public:
    void update();

    Command command() const;

private:
    Command command_ = Command::None;
};