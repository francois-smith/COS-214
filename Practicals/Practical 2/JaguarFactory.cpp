/*
 * JaguarFactory.cpp
 *
 *  Created on: 04 Aug 2022
 *      Author: Francois Smith
 */

#include "JaguarFactory.h"
#include "Jaguar.h"

Enemy *JaguarFactory::createEnemy(std::string attack, std::string defense)
{
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed1);
    std::normal_distribution<double> distribution(10.0,3.0);
    std::string name = this->getName();
    int hp = (int) round(distribution(generator));
    Jaguar* jaguar = new Jaguar(hp, 2, attack, name, defense);
    return jaguar;
}