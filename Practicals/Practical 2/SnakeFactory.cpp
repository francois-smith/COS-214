/*
 * SnakeFactory.cpp
 *
 *  Created on: 04 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include "SnakeFactory.h"
#include "Snake.h"

Enemy* SnakeFactory::createEnemy(std::string attack, std::string defense)
{
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed1);
    std::normal_distribution<float> distribution(6.0,1.0);
    std::string name = this->getName();
    int hp = (int) round(distribution(generator));
    Snake* snake = new Snake(hp, 2, attack, name, defense);
    return snake;
}
