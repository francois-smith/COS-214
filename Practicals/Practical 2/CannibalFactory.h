/*
 * CannibalFactory.cpp
 *
 *  Created on: 04 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include "EnemyFactory.h"

/**
 * Subclass of EnemyFactory, creates classes of the Cannibal Enemy type. \n
 * Includes overridden createEnemy method to create Cannibals.
 */
class CannibalFactory: public EnemyFactory
{
public:
    Enemy* createEnemy (std::string attack, std::string defense) override;

protected:
    std::string getName() override;
};
