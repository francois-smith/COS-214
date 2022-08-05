/*
 * EnemyState.cpp
 *
 *  Created on: 07 Aug 2022
 *      Author: Francois Smith
 */

#include "EnemyState.h"

/**
 * @brief EnemyState constructor. Stores all values that need to be saved for an enemy.
 * @param hp - HP of the enemy.
 * @param dmg - Damage of the enemy.
 * @param atk - Attack move of the enemy.
 * @param def - Defense move of the enemy.
 * @param name - Name of the enemy.
 */
EnemyState::EnemyState(int hp, int dmg, std::string& atk, std::string& def, std::string& name)
{
    this->hp = hp;
    this->dmg = dmg;
    this->atk = atk;
    this->def = def;
    this->name = name;
}

/**
 * @brief Getter for the HP stored in the state.
 * @return HP in the state.
 */
int EnemyState::getHp() const
{
    return this->hp;
}

/**
 * @brief Getter for the Damage stored in the state.
 * @return Damage in the state.
 */
int EnemyState::getDmg() const
{
    return this->dmg;
}

/**
 * @brief Getter for the Attack Move stored in the state.
 * @return Attack Move in the state.
 */
std::string EnemyState::getAtk() const
{
    return this->atk;
}

/**
 * @brief Getter for the Defense Move HP stored in the state.
 * @return Defense Move in the state.
 */
std::string EnemyState::getDef() const
{
    return this->def;
}

/**
 * @brief Getter for the name stored in the state.
 * @return Name in the state.
 */
std::string EnemyState::getName() const
{
    return this->name;
}


