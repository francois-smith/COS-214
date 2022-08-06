/*
 * CannibalFactory.cpp
 *
 *  Created on: 04 Aug 2022
 *      Author: Francois Smith
 */

#include "CannibalFactory.h"
#include "Cannibal.h"

std::string CannibalFactory::getName() {
    return "Cannibal";
}

Enemy *CannibalFactory::createEnemy(std::string attack, std::string defense)
{
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distribution(8,30);
    std::string name = this->getName();
    int hp = (int) round(distribution(generator));
    Cannibal* cannibal = new Cannibal(hp, 2, attack, name, defense);
    return cannibal;
}
