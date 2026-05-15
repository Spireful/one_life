#pragma once
#include <string>
#include <iostream>

struct Player
{
    std::string name{};
    int maxHp{50};
    int hp{50};
    int meleeAttack{10};
    int defence{5};
};

struct Enemy
{
    std::string name{};
    int maxHp{};
    int hp{};
    int meleeAttack{};
    int defence{};
};

inline Enemy spider{"Spider", 25, 25, 5, 3};
