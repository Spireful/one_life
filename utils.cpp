#include "structs.h"
#include "utils.h"
#include <iostream>
#include <string>
#include <random>

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
            std::cout << "You have defeated the Spider! \n";
            return;
        }

        std::cout << "Press 1 to Attack\nPress 2 to Run\nPress 3 to check Status\n";
        int input = askIntInput();
        if (input == 1)
        {
            int temp_player_attack{randomDamage(player.meleeAttack)};
            spider.hp -= temp_player_attack;
            std::cout << "You have dealt " << temp_player_attack << " Damage!\n";
            if (spider.hp <= 0)
            {
                std::cout << "You have defeated the Spider! \n";
                return;
            }
            int temp_spider_attack{randomDamage(spider.meleeAttack)};
            player.hp -= temp_spider_attack;
            std::cout << "The Spider has dealt " << temp_spider_attack << " Damage!\n";
        }
        else if (input == 2)
        {
            std::cout << player.name << " runs!\n";
            player.hp -= 10;
            return;
        }
        else if (input == 3)
        {
            std::cout << "Player has " << player.hp << "health remaining! \n"
                      << "Spider has " << spider.hp << "health remaining! \n";
        }
    }
}

int randomDamage(int attack)
{
    static std::mt19937 rng{std::random_device{}()};
    std::uniform_int_distribution<> distr((attack * 8) / 10, (attack * 12) / 10);
    return distr(rng);
}
