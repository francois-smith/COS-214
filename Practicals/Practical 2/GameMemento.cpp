/*
 * GameMemento.cpp
 *
 *  Created on: 07 Aug 2022
 *      Author: Francois Smith
 */

#include "GameMemento.h"

/**
 * @brief Enemy Memento class. Stores state object, which contains all values for enemy.
 */
GameMemento::GameMemento(GameState* state)
{
    this->state = state;
}

/**
 * @brief Clears memory used to store the state.
 */
GameMemento::~GameMemento()
{
    delete this->state;
}

/**
 * @brief Setter for the state stored in the memento.
 */
void GameMemento::setState(GameState* newState)
{
    this->state = newState;
}

/**
 * @brief Getter for the state stored in the memento.
 * @return State stored in the memento.
 */
GameState* GameMemento::getState() const
{
    return this->state;
}
