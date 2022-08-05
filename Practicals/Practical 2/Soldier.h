/*
 * Commander.h
 *
 *  Created on: 05 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include "SquadMember.h"

/**
 * Subclass of SquadMember, represents a Soldier SquadMember type. \n
 * Implements prototype pattern to allow for cloning.
 */
class Soldier: public SquadMember
{
public:
    //Constructor and Prototype Methods
    Soldier();
    Soldier(int hp, int dmg);
    Soldier(int hp, int dmg, std::string& name);

    SquadMember* clone() override;
    std::string generateName() override;
};

