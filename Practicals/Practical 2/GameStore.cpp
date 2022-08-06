/*
 * GameStore.cpp
 *
 *  Created on: 07 Aug 2022
 *      Author: Francois Smith
 */

#include "GameStore.h"

/**
 * @brief GameStore constructor.
 * @param enemy - Enemy to be linked to store.
 * @param squadMembers - SquadMembers to be linked to store.
 */
GameStore::GameStore(Enemy* enemyRef, std::vector<SquadMember*>& squadMember)
{
    this->enemy = enemyRef;
    this->squadMembers = std::vector<SquadMember*>();
    for(SquadMember* member : squadMember)
    {
        SquadMember* clonedMember = member->clone();
        std::string name = member->getName();
        clonedMember->setName(name);
        this->squadMembers.push_back(clonedMember);
    }
}

/**
 * @brief GameStore destructor, calls function to clear save history.
 */
GameStore::~GameStore()
{
    this->clear();
}

/**
 * @brief Clears all stored EnemyMementos.
 */
void GameStore::clear()
{
    for(GameMemento* save: saveHistory)
    {
        delete save;
    }
    saveHistory.clear();
}

/**
 * @brief Saves the current state of the enemy.
 */
void GameStore::save()
{
    EnemyState* enemyState = enemy->saveGame();
    std::vector<SquadMemberState*> squadMemberStates;
    for(SquadMember* member: squadMembers)
    {
        squadMemberStates.push_back(member->saveGame());
    }

    GameState* state = new GameState(enemyState, squadMemberStates);
    GameMemento* save = new GameMemento(state);
    saveHistory.push_back(save);
}

/**
 * @brief Restores previous save.
 */
void GameStore::load()
{
    if(saveHistory.empty())
    {
        std::cout << "No previous saves found." << std::endl;
        return;
    }

    GameMemento* save = saveHistory.back();
    enemy->loadSave(save->getState()->getEnemyState());
    for(int i = 0; i < save->getState()->getSquadMemberStates().size(); i++)
    {
        squadMembers.at(i)->loadSave(save->getState()->getSquadMemberStates().at(i));
    }
    saveHistory.pop_back();
    delete save;
}

/**
 * @brief Sets the enemy to be saved.
 * @param enemy - Enemy to be saved.
 */
void GameStore::setEnemy(Enemy* newEnemy)
{
    this->enemy = newEnemy;
}

/**
 * @brief Gets the enemy that save objects links to.
 * @return Enemy that is saved.
 */
Enemy* GameStore::getEnemy() const
{
    return this->enemy;
}

/**
 * @brief Sets the SquadMembers to be saved.
 * @param enemy - SquadMembers to be saved.
 */
void GameStore::setSquadMembers(std::vector<SquadMember*>& newSquadMembers)
{
    //Delete all previous SquadMember references.
    for(SquadMember* member : this->squadMembers)
    {
        delete member;
    }
    this->squadMembers.clear();

    //Clone all new SquadMember references.
    this->squadMembers = std::vector<SquadMember*>();
    for(SquadMember* member : newSquadMembers)
    {
        SquadMember* clonedMember = member->clone();
        std::string name = member->getName();
        clonedMember->setName(name);
        this->squadMembers.push_back(clonedMember);
    }
}

/**
 * @brief Gets the SquadMembers that save objects links to.
 * @return SquadMembers that are saved.
 */
std::vector<SquadMember*> GameStore::getSquadMembers() const
{
    return this->squadMembers;
}
