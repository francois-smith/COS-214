/*
 * GorillaFactory.h
 *
 *  Created on: 04 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include "EnemyFactory.h"

/**
 * Subclass of EnemyFactory, creates classes of the Gorilla Enemy type. \n
 * Includes overridden createEnemy method to create Gorillas.
 */
class GorillaFactory: public EnemyFactory {
public:
    Enemy* createEnemy (std::string attack, std::string defense) override;
};
