#pragma once

#include "./ActorController.hpp"

class AiController : public ActorController {
public:
    Command decide(const World&, const Actor&) override;
};