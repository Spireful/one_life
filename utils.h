#pragma once
#include "structs.h"

int askIntInput();
std::string getUserName();
void intro();
void encounterSpider(Player &player, Enemy &spider);
void combatSpider(Player &player, Enemy &spider);
