/*
 * Gorilla.cpp
 *
 *  Created on: 02 Aug 2022
 *      Author: Francois Smith
 */

#include "Gorilla.h"

Gorilla::Gorilla(int hp, int dmg, std::string &atk, std::string &name, std::string &def) : Enemy(hp, dmg, atk, name,def) {}

bool Gorilla::hitSquadMember(SquadMember* z)
{
    if(z == nullptr) return false;

    std::cout << "Gorilla slams his fists on the ground, growls and hits " << z->getName() << " with " << this->getAtk() << "." << std::endl;
    if(z->takeDamage(this->getDmg()) <= 0)
    {
        return true;
    }
    else {
        return false;
    }
}

void Gorilla::celebrate()
{
    std::cout << "Player tried in vain trying to save him self." << std::endl;
}

bool Gorilla::getHit(SquadMember* z)
{
    if(z == nullptr) return false;

    std::cout << "Roars and hits his chest in anger." << std::endl;
    this->setHP(this->getHP() - z->getDmg());
    if(this->getHP() <= 0)
    {
        return true;
    }
    else {
        return false;
    }
}

void Gorilla::die()
{
    std::cout << "The earth shakes as the gorilla falls to the ground." << std::endl;
}
