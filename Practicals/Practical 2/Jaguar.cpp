/*
 * Jaguar.cpp
 *
 *  Created on: 02 Aug 2022
 *      Author: Francois Smith
 */

#include "Jaguar.h"

Jaguar::Jaguar(int hp, int dmg, std::string &atk, std::string &name, std::string &def) : Enemy(hp, dmg, atk, name,def) {}

bool Jaguar::hitSquadMember(SquadMember* z)
{
    if(z == nullptr) return false;

    std::cout << "Jaguar leaps toward the  " << z->getName() << " and delivers a forceful " << this->getAtk() << "." << std::endl;
    if(z->takeDamage(this->getDmg()) <= 0)
    {
        return true;
    }
    else {
        return false;
    }
}

void Jaguar::celebrate()
{
    std::cout << "Should have fought harder soldier." << std::endl;
}

bool Jaguar::getHit(SquadMember* z)
{
    if(z == nullptr) return false;

    std::cout << "Growls in pain as he is maimed. Jaguar turns around and delivers " << this->getDef() << " against" << z->getName() << "." << std::endl;
    this->setHP(this->getHP() - z->getDmg());
    if(this->getHP() <= 0)
    {
        return true;
    }
    else {
        return false;
    }
}

void Jaguar::die()
{
    std::cout << "Gives one last growl before falling over" << std::endl;
}
