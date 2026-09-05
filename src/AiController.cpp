#include "AiController.hpp"

Command AiController::decide(const World& world, const Actor& actor) {
    return Command::MoveEast;
}