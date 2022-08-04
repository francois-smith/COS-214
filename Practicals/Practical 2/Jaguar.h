#pragma once
#include "Enemy.h"
#include "JaguarFactory.h"

class Jaguar: public Enemy {
    Jaguar(int hp, int dmg, std::string& atk, std::string& name, std::string& def);
    bool hitSquadMember(SquadMember* z) override;
    bool getHit(SquadMember* z) override;
    void celebrate() override;
    void die() override;
    friend class JaguarFactory;
};
