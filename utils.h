#pragma once
#include "structs.h"

int askIntInput();
int checkDamage(int damage);
void combatEnemy(Player &player, Enemy &Enemy);
void displayStats(Player &player);
void encounterEnemy(Player &player, Enemy &Enemy);
std::string getUserName();
void intro();
void layerOne(Player &player);
int playerDied(Player &player);
int randomDamage(int attack);
