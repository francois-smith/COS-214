/*
 * EnemyStore.h
 *
 *  Created on: 07 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include "Enemy.h"
#include "EnemyMemento.h"
#include <vector>

/**
 * @brief The EnemyStore class is the caretaker that stores the EnemyMementos.
 */
class EnemyStore
{
public:
    //Constructor and Destructor
    explicit EnemyStore(Enemy* enemy);
    ~EnemyStore();

    //Member Functions
    void undo();
    void save();
    void clear();

    //Getter and Setter
    void setEnemy(Enemy* enemy);
    Enemy* getEnemy() const;

private:
    Enemy* enemy;
    std::vector<EnemyMemento*> history;
};
