#pragma once
#include "structs.h"

int askIntInput();
int checkDamage(int damage);
void combatEnemy(Player &player, Enemy &enemy);
void displayStats(Player &player);
void encounterEnemy(Player &player, Enemy &enemy);
std::string getUserName();
void intro();
void layerOne(Player &player);
void levelUp(Player &player, int layer);
bool playerDied(Player &player);
int randomDamage(int attack);
int randomOneToFour();
