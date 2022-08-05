/*
 * EnemyStore.cpp
 *
 *  Created on: 07 Aug 2022
 *      Author: Francois Smith
 */

#include "EnemyStore.h"

/**
 * @brief EnemyStore constructor.
 * @param enemy - Enemy to be linked to store.
 */
EnemyStore::EnemyStore(Enemy *enemy)
{
    this->enemy = enemy;
}

EnemyStore::~EnemyStore()
{
    for(EnemyMemento* save: history)
    {
        delete save;
    }
    history.clear();
}

/**
 * @brief Clears all stored EnemyMementos.
 */
void EnemyStore::clear()
{
    for(EnemyMemento* save: history)
    {
        delete save;
    }
    history.clear();
}

/**
 * @brief Saves the current state of the enemy.
 */
void EnemyStore::save()
{
    history.push_back(enemy->saveGame());
}

/**
 * @brief Restores previous save.
 */
void EnemyStore::undo()
{
    if (history.empty())
    {
        std::cout << "No previous saves found." << std::endl;
        return;
    }

    EnemyMemento* save = history.back();
    enemy->loadSave(save);
    history.pop_back();
    delete save;
}

/**
 * @brief Sets the enemy to be saved.
 * @param enemy - Enemy to be saved.
 */
void EnemyStore::setEnemy(Enemy *enemy)
{
    this->enemy = enemy;
}

/**
 * @brief Gets the enemy that save objects link to saved.
 * @return Enemy that is saved.
 */
Enemy* EnemyStore::getEnemy() const
{
    return this->enemy;
}
