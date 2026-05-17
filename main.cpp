#include "structs.h"
#include "utils.h"
#include <iostream>
#include <string>

int main()
{
    std::cout << "Welcome to One-Life \n";
    Player player;
    player.name = getUserName();

    intro();
    layerOne(player);
}
