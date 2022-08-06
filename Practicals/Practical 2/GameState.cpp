/*
 * GameState.cpp
 *
 *  Created on: 07 Aug 2022
 *      Author: Francois Smith
 */

#include "GameState.h"

/**
 * @brief Base constructor for GameState. Stores states of SquadMembers and Enemies.
 * @param enemyState - EnemyState of the game.
 * @param squadMemberStates - Vector of SquadMemberStates of the game.
 */
GameState::GameState(EnemyState *enemyState, std::vector<SquadMemberState*> squadMemberStates)
{
    this->enemyState = enemyState;
    this->squadMemberStates = squadMemberStates;
}

/**
 * @return Vector of SquadMemberStates.
 */
std::vector<SquadMemberState *> GameState::getSquadMemberStates() const
{
    return  this->squadMemberStates;
}

/**
 * @return EnemyState Pointer.
 */
EnemyState *GameState::getEnemyState() const
{
    return this->enemyState;
}
