#pragma once
#include "Enemy.h"

class Gorilla: public Enemy {
    Gorilla(int hp, int dmg, std::string& atk, std::string& def);
    ~Gorilla() override = 0;
    bool hitSquadMember(SquadMember* z) override;
    bool getHit(SquadMember* z) override;
    void celebrate() override;
    void die() override;
};
