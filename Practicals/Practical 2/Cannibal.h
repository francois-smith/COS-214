/*
 * Cannibal.h
 *
 *  Created on: 02 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include "Enemy.h"
#include "CannibalFactory.h"

/**
 * Subclass of Enemy, represents a Cannibal enemy type. \n
 * All methods are private to uphold the factory method and only factories can produce cannibals.
 */
class Cannibal: public Enemy
{
    //Constructor
    Cannibal(int hp, int dmg, std::string& atk, std::string& name, std::string& def);

    //Template Methods
    bool hitSquadMember(SquadMember* z) override;
    bool getHit(SquadMember* z) override;
    void celebrate() override;
    void die() override;
    friend class CannibalFactory;
};
