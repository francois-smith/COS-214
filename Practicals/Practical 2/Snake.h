/*
 * Snake.h
 *
 *  Created on: 02 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include "Enemy.h"
#include "SnakeFactory.h"

/**
 * Subclass of Enemy, represents a Snake enemy type. \n
 * All methods are private to uphold the factory method and only factories can produce snakes.
 */
class Snake: public Enemy
{
    //Constructor
    Snake(int hp, int dmg, std::string& atk, std::string& name, std::string& def);

    //Template Methods

    bool hitSquadMember(SquadMember* z) override;
    bool getHit(SquadMember* z) override;
    void celebrate() override;
    void die() override;
    friend class SnakeFactory;

    //Used for debugging purposes
    friend void debugGame();
};
