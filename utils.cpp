#include "structs.h"
#include "utils.h"
#include <iostream>
#include <string>

int askIntInput()
{
    std::cout << ">> ";
    int input{};
    std::cin >> input;

    return input;
}

std::string getUserName()
{
    std::cout << "What's your name, adventurer? \n>> ";
    std::string playerName{};
    std::cin >> playerName;

    return playerName;
}

void intro()
{
    std::cout << "\nYou wake up from a sleep. \n"
                 "You don't realise where you are.. it just looks, strange. \n"
                 "You decide to explore the place. \n\n";
}

void encounterSpider(Player &player, Enemy &spider)
{
    std::cout << "You encounter a Spider";
    combatSpider(player, spider);
}

void combatSpider(Player &player, Enemy &spider)
{
    while (true)
    {
        if (player.hp <= 0)
        {
            std::cout << "You died! \n";
            return;
        }
        else if (spider.hp <= 0)
        {
            std::cout << "You defeated the Spider! \n";
            return;
        }

        std::cout << "Press 1 to Attack\nPress 2 to Run\n";
        int input = askIntInput();
        if (input == 1)
        {
            spider.hp -= player.meleeAttack;
        }
        else if (input == 2)
        {
            std::cout << player.name << " runs!\n";
            player.hp -= 10;
            return;
        }
    }
}
