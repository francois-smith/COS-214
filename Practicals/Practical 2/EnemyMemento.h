/*
 * EnemyMemento.h
 *
 *  Created on: 07 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include "EnemyState.h"

/**
 * @brief Enemy Memento class. Stores state object, which contains all values for enemy.
 */
class EnemyMemento
{
public:
    //Destructor
    ~EnemyMemento();

private:
    //Constructor and Friend Declaration
    friend class Enemy;
    explicit EnemyMemento(EnemyState* state);

    //Getter and Setter
    void setState(EnemyState* newState);
    EnemyState* getState() const;

    //Member Variable
    EnemyState* state;
};
