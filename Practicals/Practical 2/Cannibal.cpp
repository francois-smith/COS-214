#include "Cannibal.h"

Cannibal::Cannibal(int hp, int dmg, std::string &atk, std::string &def) : Enemy(hp, dmg, atk, def) {}

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

bool Cannibal::getHit(SquadMember* z)
{
    if(z == nullptr) return false;

    std::cout << "The other villagers come running deploying " << this->getDef() << "." << std::endl;
    int health = this->getHP() - z->getDmg();
    if(health <= 0)
    {
        return true;
    }
    else {
        this->setHP(health);
        return false;
    }
}

void Cannibal::celebrate()
{
    std::cout << "Shakes his " << this->getAtk() << " at the player’s remains." << std::endl;

}

void Cannibal::die()
{
    std::cout << "Screams with his last breath, “I am your father’." << std::endl;
}
