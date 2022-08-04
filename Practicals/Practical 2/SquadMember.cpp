#include "SquadMember.h"

SquadMember::SquadMember(int hp, std::string& name, int dmg)
{
    this->hp = hp;
    this->name = name;
    this->dmg = dmg;
}

void SquadMember::setHP(int newHp)
{
    this->hp = newHp;
}

std::string SquadMember::getName() const
{
    return this->name;
}

int SquadMember::takeDamage(int damage)
{
    setHP(this->hp - damage);
    return this->hp;
}

int SquadMember::getHP() const
{
    return this->hp;
}

void SquadMember::die()
{

}

int SquadMember::getDmg() const
{
    return this->dmg;
}

void SquadMember::setDmg(int newDmg)
{
    this->dmg = newDmg;
}

SquadMember *SquadMember::clone()
{
    return new SquadMember(this->hp, this->name, this->dmg);
}
