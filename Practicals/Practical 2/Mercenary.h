/*
 * Mercenary.h
 *
 *  Created on: 05 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include "SquadMember.h"
#include <random>

/**
 * Subclass of SquadMember, represents a Mercenary SquadMember type. \n
 * Implements prototype pattern to allow for cloning.
 */
class Mercenary: public SquadMember
{
public:
    //Constructor and Prototype Methods
    Mercenary();
    Mercenary(int hp, int dmg);
    Mercenary(int hp, int dmg, std::string& name);

    SquadMember* clone() override;
    std::string generateName() override;
};
