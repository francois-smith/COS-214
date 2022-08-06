/*
 * EnemyFactory.h
 *
 *  Created on: 04 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include "Enemy.h"
#include <ctime>
#include <string>
#include <random>
#include <chrono>

/**
 * Abstract factory class used to create enemies. \n
 * Contains a method that returns created instances of enemies, as well as a name generator for enemies.
 */
class EnemyFactory
{
public:
    //Constructor and Destructor
    EnemyFactory() = default;
    virtual ~EnemyFactory() = default;

    //Factory Method
    /**
     * @brief Creates and returns a pointer to a new Enemy. \n
     * @brief Returns base class type to allow numerous types of enemies to be stored in a single array.
     * @param attack - Attack Value Of Enemy
     * @param defense - Defense Value Of Enemy
     * @return Pointer to newly created enemy
     */
    virtual Enemy* createEnemy(std::string attack, std::string defense) = 0;

protected:
    //Helper Functions

    /**
     * @brief Generates a name for an enemy.
     * @return Generated Name
    */
    virtual std::string getName() = 0;
};

