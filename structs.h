#pragma once
#include <string>
#include <iostream>

struct Player
{
    std::string name{};
    int maxHp{125};
    int hp{125};
    int meleeAttack{2120};
    int defence{521};
};

struct Enemy
{
    std::string name{};
    int maxHp{};
    int hp{};
    int meleeAttack{};
    int defence{};
};

inline Enemy spider{"Spider", 35, 35, 8, 4};
inline Enemy goblin{"Goblin", 75, 75, 17, 9};
inline Enemy ayush{"Ayush", 125, 125, 30, 15};
