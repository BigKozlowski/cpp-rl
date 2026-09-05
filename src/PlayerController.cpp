#include "PlayerController.hpp"

Command PlayerController::decide(const World&, const Actor&) 
{
    return input_.command();
}

PlayerController::PlayerController(Input& input)
    : input_(input)
{
}