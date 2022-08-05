/*
 * EnemyMemento.cpp
 *
 *  Created on: 07 Aug 2022
 *      Author: Francois Smith
 */

#include "EnemyMemento.h"

/**
 * @brief Enemy Memento class. Stores state object, which contains all values for enemy.
 */
EnemyMemento::EnemyMemento(EnemyState *state)
{
    this->state = state;
}

/**
 * @brief Clears memory used to store the state.
 */
EnemyMemento::~EnemyMemento()
{
    delete this->state;
}

/**
 * @brief Setter for the state stored in the memento.
 */
void EnemyMemento::setState(EnemyState* newState)
{
    this->state = newState;
}

/**
 * @brief Getter for the state stored in the memento.
 * @return State stored in the memento.
 */
EnemyState* EnemyMemento::getState() const
{
    return this->state;
}
