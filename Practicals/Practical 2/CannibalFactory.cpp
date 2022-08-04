/*
 * CannibalFactory.cpp
 *
 *  Created on: 04 Aug 2022
 *      Author: Francois Smith
 */

#include "CannibalFactory.h"
#include "Cannibal.h"

Enemy *CannibalFactory::createEnemy(std::string attack, std::string defense) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(30,8);
    std::string name = this->getName();
    return new Cannibal(distribution(generator), 6, attack, name, defense);
}
