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
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(4,12);
    std::string name = this->getName();
    return new Gorilla(distribution(generator), 6, attack, name, defense);
}
