#include "EnemyFactory.h"

std::string EnemyFactory::getName() {
    std::string names[] = {"Snake", "Gorilla", "Jaguars", "Cannibal"};
    srand(time(nullptr));
    return names[rand() % 4];
}
