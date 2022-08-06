/*
 * SquadMemberState.cpp
 *
 *  Created on: 07 Aug 2022
 *      Author: Francois Smith
 */

#include "SquadMemberState.h"

/**
 * @brief SquadMemberState constructor. Stores all values that need to be saved for a SquadMember.
 * @param hp - HP of the SquadMember.
 * @param dmg - Damage of the SquadMember.
 * @param type - Type of SquadMember.
 * @param name - Name of the SquadMember.
 */
SquadMemberState::SquadMemberState(int hp, int dmg, std::string& type, std::string& name)
{
    this->hp = hp;
    this->dmg = dmg;
    this->type = type;
    this->name = name;
}

/**
 * @brief Getter for the HP stored in the state.
 * @return HP in the state.
 */
int SquadMemberState::getHp() const
{
    return this->hp;
}

/**
 * @brief Getter for the Damage stored in the state.
 * @return Damage in the state.
 */
int SquadMemberState::getDmg() const
{
    return this->dmg;
}

/**
 * @brief Getter for the Type stored in the state.
 * @return Type in the state.
 */
std::string SquadMemberState::getType() const
{
    return this->type;
}

/**
 * @brief Getter for the name stored in the state.
 * @return Name in the state.
 */
std::string SquadMemberState::getName() const
{
    return this->name;
}