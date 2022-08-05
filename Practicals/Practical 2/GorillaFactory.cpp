/*
 * GorillaFactory.cpp
 *
 *  Created on: 04 Aug 2022
 *      Author: Francois Smith
 */

#include "GorillaFactory.h"
#include "Gorilla.h"

Enemy *GorillaFactory::createEnemy(std::string attack, std::string defense)
{
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distribution(4,12);
    std::string name = this->getName();
    int hp = (int) round(distribution(generator));
    Gorilla* gorilla = new Gorilla(hp, 2, attack, name, defense);
    return gorilla;
}
