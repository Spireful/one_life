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
    std::cout << '\n';

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
                 "You decide to explore the place. \n\n"
                 "Layer ONE. \n";
}

void encounterEnemy(Player &player, Enemy &enemy)
{
    std::cout << "You encounter a " << enemy.name << '\n';
    combatEnemy(player, enemy);
}

void combatEnemy(Player &player, Enemy &enemy)
{
    while (true)
    {
        if (playerDied(player) == true)
        {
            std::cout << "You died! \n";
            return;
        }

        std::cout << "Press 1 to Attack\n"
                     "Press 2 to Run\n"
                     "Press 3 to check Status\n";

        int input = askIntInput();
        if (input == 1)
        {
            // Combat System
            // Checks enemy health, does random damage to both
            int temp_player_attack{randomDamage(player.meleeAttack) - enemy.defence};
            temp_player_attack = checkDamage(temp_player_attack);
            enemy.hp -= temp_player_attack;
            std::cout << "You have dealt " << temp_player_attack << " Damage!\n";
            if (enemy.hp <= 0)
            {
                std::cout << "You have defeated " << enemy.name << "! \n";
                enemy.hp = enemy.maxHp;
                return;
            }
            int temp_enemy_attack{randomDamage(enemy.meleeAttack) - player.defence};
            temp_enemy_attack = checkDamage(temp_enemy_attack);
            player.hp -= temp_enemy_attack;
            std::cout << "The Spider has dealt " << temp_enemy_attack << " Damage!\n";
        }
        else if (input == 2)
        {
            std::cout << player.name << " runs!\n";
            player.hp -= enemy.meleeAttack / 2;
            std::cout << enemy.name << "'s attack grazed you \n";
            std::cout << "You have taken " << enemy.meleeAttack / 2 << " damage \n\n";
            return;
        }
        else if (input == 3)
        {
            std::cout << "Player has " << player.hp << "health remaining! \n"
                      << enemy.name << " has " << enemy.hp << "health remaining! \n";
        }
    }
}

int randomDamage(int attack)
{
    static std::mt19937 rng{std::random_device{}()};
    std::uniform_int_distribution<> distr((attack * 8) / 10, (attack * 12) / 10);
    return distr(rng);
}

void layerOne(Player &player)
{
    int layerOneVar{};
    while (true)
    {
        std::cout << "Press 1 to continue roaming \n"
                     "Press 2 to check stats \n";
        if (layerOneVar >= 5)
        {
            std::cout << "Press 3 to go deeper into the layer \n";
        }

        int choice{askIntInput()};
        if (choice == 1)
        {
            encounterEnemy(player, spider);
        }
        else if (choice == 2)
        {
            displayStats(player);
        }
        layerOneVar += 1;
    }
}

void displayStats(Player &player)
{
    std::cout << "Stats: \n"
                 "Max HP: "
              << player.maxHp << "\n"
                                 "HP: "
              << player.hp << "\n"
                              "Melee Attack: "
              << player.meleeAttack << "\n"
                                       "Defence: "
              << player.defence << "\n";
}

int checkDamage(int damage)
{
    if (damage < 0)
    {
        return 0;
    }
    else
        return damage;
}

int playerDied(Player &player)
{
    if (player.hp <= 0)
    {
        return true;
    }
    return false;
}
