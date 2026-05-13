#include "utils.h"

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
