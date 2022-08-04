#pragma once
#include "SquadMember.h"

class Commander: public SquadMember
{
public:
    Commander(int hp, std::string& name, int dmg);
    Commander* clone() override;
    std::string generateName() override;
};
