#pragma once
#include "structs.h"

int askIntInput();
void combatEnemy(Player &player, Enemy &enemy);
void displayStats(Player &player);
void encounterEnemy(Player &player, Enemy &enemy);
std::string getUserName();
void intro();
void layerOne(Player &player);
void layerTwo(Player &player);
void layerThree(Player &player);
void levelUp(Player &player, int layer);
bool playerDied(Player &player);
int random(int first, int second);
int randomDamage(int attack);
int returnValidHp(Player &player);
void showChoice(int layerVar);
