#include "structs.h"
#include "utils.h"
#include <iostream>
#include <string>
#include <random>
int layer{};

int askIntInput()
{
    std::cout << ">> ";
    int input{};
    std::cin >> input;
    std::cout << '\n';

    return input;
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
                     "Press 3 to Check Status\n";

        int input = askIntInput();
        if (input == 1)
        {
            // Combat System
            // Checks enemy health, does random damage to both within 25/20% - defence/2
            int temp_player_attack{randomDamage(player.meleeAttack) - enemy.defence / 2};
            temp_player_attack = checkDamage(temp_player_attack);
            enemy.hp -= temp_player_attack;
            std::cout << "You have dealt " << temp_player_attack << " Damage!\n";
            if (enemy.hp <= 0)
            {
                std::cout << "You have defeated " << enemy.name << "! \n\n";
                levelUp(player, layer);
                // Heals player
                if (random(1, 4) == 1)
                {
                    std::cout << "You have received a potion! \n"
                                 "You drank the potion and healed up to max HP! \n";
                    player.hp = player.maxHp;
                }
                else
                {
                    std::cout << "You ate the remains of " << enemy.name
                              << " (Ew) and have gained " << player.maxHp / 10 << " HP! \n";
                    player.hp = returnValidHp(player);
                }
                enemy.hp = enemy.maxHp;
                return;
            }

            int temp_enemy_attack{randomDamage(enemy.meleeAttack) - player.defence / 2};
            temp_enemy_attack = checkDamage(temp_enemy_attack);
            player.hp -= temp_enemy_attack;
            std::cout << enemy.name << " has dealt " << temp_enemy_attack << " Damage!\n";
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

void encounterEnemy(Player &player, Enemy &enemy)
{
    std::cout << "You encounter a " << enemy.name << '\n';
    combatEnemy(player, enemy);
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

void layerOne(Player &player)
{
    layer = 1;
    int layerOneVar{};
    while (true)
    {
        showChoice(layerOneVar);

        int choice{askIntInput()};
        if (choice == 1)
        {
            layerOneVar += 1;
            encounterEnemy(player, spider);
            if (playerDied(player))
            {
                return;
            }
        }
        else if (choice == 2)
        {
            displayStats(player);
        }
        else if (choice == 3 && layerOneVar >= 5)
        {
            layerTwo(player);
            return;
        }
    }
}

void layerTwo(Player &player)
{
    std::cout << "You have reached deeper into the cave.. \n";
    layer = 2;
    int layerTwoVar{};
    while (true)
    {
        showChoice(layerTwoVar);
        int choice{askIntInput()};
        if (choice == 1)
        {
            layerTwoVar += 1;
            encounterEnemy(player, goblin);
            if (playerDied(player))
            {
                return;
            }
        }
        else if (choice == 2)
        {
            displayStats(player);
        }
        else if (choice == 3 && layerTwoVar >= 5)
        {
            layerThree(player);
            return;
        }
    }
    return;
}

void layerThree(Player &player)
{
    std::cout << "You notice a suspecious looking rock \n"
              << "You slide it.. and see a humongous beast, very handsome \n"
              << "Fight to the death tho \n";
    combatEnemy(player, ayush);
    if (!playerDied(player))
    {
        std::cout << "You won! \n";
    }
    return;
}

void levelUp(Player &player, int layer)
{
    std::cout << "You have leveled up! \n";
    if (layer == 1)
    {
        std::cout << "Do you want to increase: \n"
                  << "1. Max HP by " << 5 << '\n'
                  << "2. Attack by " << 2 << '\n'
                  << "3. Defence by " << 1 << '\n';
        int choice{};
        do
        {
            choice = askIntInput();
            if (choice == 1)
            {
                player.maxHp += 5;
            }
            else if (choice == 2)
            {
                player.meleeAttack += 2;
            }
            else if (choice == 3)
            {
                player.defence += 1;
            }
        } while (choice != 1 && choice != 2 && choice != 3);
    }
    else if (layer == 2)
    {
        std::cout << "Do you want to increase: \n"
                  << "1. Max HP by " << 10 << '\n'
                  << "2. Attack by " << 5 << '\n'
                  << "3. Defence by " << 3 << '\n';
        int choice{};
        do
        {
            choice = askIntInput();
            if (choice == 1)
            {
                player.maxHp += 5;
            }
            else if (choice == 2)
            {
                player.meleeAttack += 2;
            }
            else if (choice == 3)
            {
                player.defence += 1;
            }
        } while (choice != 1 && choice != 2 && choice != 3);
    }
}

bool playerDied(Player &player)
{
    if (player.hp <= 0)
    {
        return true;
    }
    return false;
}

int randomDamage(int attack)
{
    static std::mt19937 rng{std::random_device{}()};
    std::uniform_int_distribution<> distr((attack * 8) / 10, (attack * 12) / 10);
    return distr(rng);
}

int random(int first, int second)
{
    static std::mt19937 rng{std::random_device{}()};
    std::uniform_int_distribution<> distr(first, second);
    return distr(rng);
}

int returnValidHp(Player &player)
{
    if (player.hp + (player.maxHp / 10) >= player.maxHp)
    {
        return player.maxHp;
    }
    else
    {
        return player.hp + (player.maxHp / 10);
    }
}

void showChoice(int layerVar)
{
    std::cout << "Press 1 to continue roaming \n"
                 "Press 2 to check stats \n";
    if (layerVar >= 5)
    {
        std::cout << "Press 3 to go deeper into the layer \n";
    }
}
