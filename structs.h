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

inline Enemy spider{"Spider", 35, 35, 7, 4};
inline Enemy goblin{"Goblin", 50, 50, 12, 6};
inline Enemy ayush{"Ayush", 75, 75, 20, 10};
