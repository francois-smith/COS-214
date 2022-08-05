/*
 * Commander.h
 *
 *  Created on: 05 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include "SquadMember.h"

/**
 * Subclass of SquadMember, represents a Commander SquadMember type. \n
 * Implements prototype pattern to allow for cloning.
 */
class Commander: public SquadMember
{
public:
    //Constructor and Prototype Methods
    Commander();
    Commander(int hp, int dmg);
    Commander(int hp, int dmg, std::string& name);

    SquadMember* clone() override;
    std::string generateName() override;
};
