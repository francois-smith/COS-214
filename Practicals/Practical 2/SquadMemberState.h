/*
 * SquadMemberState.cpp
 *
 *  Created on: 07 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include <string>

/**
 * @brief SquadMemberState class. Contains all values that need to be saved for a SquadMember.
 */
class SquadMemberState
{
private:
    //Members To Store
    int hp;
    int dmg;
    std::string type;
    std::string name;

public:
    //Constructor
    SquadMemberState(int hp, int dmg, std::string& type, std::string& name);
    //Destructor
    ~SquadMemberState() = default;

    //Getters
    int getHp() const;
    int getDmg() const;
    std::string getType() const;
    std::string getName() const;
};