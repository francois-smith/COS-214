#pragma once
#include "Enemy.h"

class Jaguar: public Enemy {
    Jaguar(int hp, int dmg, std::string& atk, std::string& def);
    ~Jaguar() override = 0;
    bool hitSquadMember(SquadMember* z) override;
    bool getHit(SquadMember* z) override;
    void celebrate() override;
    void die() override;
};
