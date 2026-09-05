#include "./Input.hpp"
#include <raylib.h>

void Input::update() {
    if(IsKeyPressed(KEY_UP)) {
        command_ = Command::MoveNorth;
    } else if(IsKeyPressed(KEY_DOWN)) {
        command_ = Command::MoveSouth;
    } else if(IsKeyPressed(KEY_LEFT)) {
        command_ = Command::MoveWest;
    } else if(IsKeyPressed(KEY_RIGHT)) {
        command_ = Command::MoveEast;
    } else {
        command_ = Command::None;
    }
}

Command Input::command() const {
    return command_;
}