#pragma once
#include "SquadMember.h"
#include <string>
#include <iostream>

/**
 * Abstract class for all enemy types.
 * Defines a base attack function that follows the same logic for all enemies.
 *
 */
class Enemy {
public:
    Enemy(int hp, int dmg, std::string& atk, std::string& name, std::string& def);
    void attack(SquadMember* z);
    void setHP(int hp);
    int getHP() const;
    int getDmg() const;
    std::string getName() const;
    std::string getAtk() const;
    std::string getDef() const;
    virtual bool hitSquadMember(SquadMember* z) = 0;
    virtual bool getHit(SquadMember* z) = 0;
    virtual void celebrate() = 0;
    virtual void die() = 0;

protected:
    int hp;
    int dmg;
    std::string atk;
    std::string def;
    std::string name;
};
