/*
 * SnakeFactory.cpp
 *
 *  Created on: 04 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include "SnakeFactory.h"
#include "Snake.h"

Enemy *SnakeFactory::createEnemy(std::string attack, std::string defense)
{
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(6.0,1.0);
    std::string name = this->getName();
    return new Snake(distribution(generator), 6, attack, name, defense);
}
