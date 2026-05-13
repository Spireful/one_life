#include "utils.h"
#include <iostream>
#include <string>

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

int main()
{
    std::cout << "Welcome to One-Life \n";

    Player player;
    player.name = getUserName();
    Enemy spider{"Spider", 25, 25, 5, 3};
    std::cout << spider.maxHp;
}
