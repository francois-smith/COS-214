/*
 * Cannibal.cpp
 *
 *  Created on: 02 Aug 2022
 *      Author: Francois Smith
 */

#include "Cannibal.h"

Cannibal::Cannibal(int hp, int dmg, std::string &atk, std::string &name, std::string &def) : Enemy(hp, dmg, atk, name,def) {}

bool Cannibal::hitSquadMember(SquadMember* z)
{
    if(z == nullptr) return false;

    std::cout << "Cannibal rushes towards " << z->getName() << " with a " << this->getAtk() << "." << std::endl;
    if(z->takeDamage(this->getDmg()) <= 0)
    {
        return true;
    }
    else {
        return false;
    }
}

void Cannibal::celebrate()
{
    std::cout << "Cannibal shakes his " << this->getAtk() << " at the squad member's remains." << std::endl;
}

bool Cannibal::getHit(SquadMember* z)
{
    if(z == nullptr) return false;

    std::cout << "The other villagers come running deploying " << this->getDef() << "." << std::endl;
    this->setHP(this->getHP() - z->getDmg());
    if(this->getHP() <= 0)
    {
        return true;
    }
    else {
        return false;
    }
}

void Cannibal::die()
{
    std::cout << "Cannibal screams with his last breath, 'I am your father'." << std::endl;
}
