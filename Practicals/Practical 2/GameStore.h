/*
 * GameStore.h
 *
 *  Created on: 07 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include <vector>
#include "Enemy.h"
#include "SquadMember.h"
#include "GameMemento.h"

/**
 * @brief The GameStore class is the caretaker that stores the EnemyMementos.
 */
class GameStore
{
public:
    //Constructor and Destructor
    GameStore(Enemy* enemyRef, std::vector<SquadMember*>& squadMember);
    ~GameStore();

    //Member Functions
    void load();
    void save();
    void clear();

    //Getters and Setters
    void setEnemy(Enemy* newEnemy);
    Enemy* getEnemy() const;

    void setSquadMembers(std::vector<SquadMember*>& newSquadMembers);
    std::vector<SquadMember*> getSquadMembers() const;

private:
    Enemy* enemy;
    std::vector<SquadMember*> squadMembers;
    std::vector<GameMemento*> saveHistory;
};
