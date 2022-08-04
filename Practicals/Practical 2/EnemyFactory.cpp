/*
 * EnemyFactory.cpp
 *
 *  Created on: 04 Aug 2022
 *      Author: Francois Smith
 */

#include "EnemyFactory.h"

/**
 * Generates a random name for an enemy.
 * @return Generated Name
 */
std::string EnemyFactory::getName()
{
    std::string names[] = {"Snake", "Gorilla", "Jaguars", "Cannibal"};
    srand(time(nullptr));
    return names[rand() % 4];
}
