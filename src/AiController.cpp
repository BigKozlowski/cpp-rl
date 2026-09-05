#include "AiController.hpp"

Command AiController::decide(const World&, const Actor&) {
    return Command::MoveEast;
}