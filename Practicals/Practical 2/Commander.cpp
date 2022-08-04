#include "Commander.h"

Commander::Commander(int hp, std::string &name, int dmg) : SquadMember(hp, name, dmg) {}

Commander *Commander::clone()
{
    std::string commanderName = this->generateName();
    return new Commander(this->getHP(), commanderName, this->getDmg());
}

std::string Commander::generateName()
{
    std::string names[] = {"Antorn", "Daryen", "Trephor", "Coltan", "Braydan"};
    srand(time(nullptr));
    return names[rand() % 4];
}
