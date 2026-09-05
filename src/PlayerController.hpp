#pragma once

#include "./ActorController.hpp"
#include "Input.hpp"

class PlayerController : public ActorController {
public:
    explicit PlayerController(Input& input);
    Command decide(const World&, const Actor&) override;
    
private:
    Input& input_;
};