#pragma once
#include "Enemy.h"

class Cannibal: public Enemy {
    Cannibal(int hp, int dmg, std::string& atk, std::string& def);
    ~Cannibal() override = 0;
    bool hitSquadMember(SquadMember* z) override;
    bool getHit(SquadMember* z) override;
    void celebrate() override;
    void die() override;
};
