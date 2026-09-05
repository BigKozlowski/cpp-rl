#pragma once

#include "./Item.hpp"
#include <vector>

#define ItemId int

class Inventory {
public:
    void add(Item item);
    bool remove(ItemId id);

    const std::vector<Item>& items() const;

private:
    std::vector<Item> items_;
};