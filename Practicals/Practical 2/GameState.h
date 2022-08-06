/*
 * GameState.h
 *
 *  Created on: 07 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include "EnemyState.h"
#include "SquadMemberState.h"
#include <vector>

/**
 * GameState class. Stores states of SquadMembers and Enemies.
 */
class GameState
{
private:
    //Member Variables
    EnemyState* enemyState;
    std::vector<SquadMemberState*> squadMemberStates;

public:
    //Constructor and Destructor
    GameState(EnemyState* enemyState, std::vector<SquadMemberState*> squadMemberStates);
    ~GameState() = default;

    //Getters
    std::vector<SquadMemberState*> getSquadMemberStates() const;
    EnemyState* getEnemyState() const;
};
