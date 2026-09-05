#pragma once

enum class Command {
    None,

    MoveNorth,
    MoveSouth,
    MoveWest,
    MoveEast,

    Wait,

    Interact,
    Pickup,
    OpenInventory,
};