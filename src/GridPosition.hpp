#pragma once

class GridPosition {
private:

public:
    int x;
    int y;
    bool operator==(const GridPosition& other) const {
        return x == other.x && y == other.y;
    }

    GridPosition operator+(const GridPosition& other) {
        return {
            .x = x + other.x,
            .y = y + other.y
        };
    }

    GridPosition& operator+=(const GridPosition& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
};