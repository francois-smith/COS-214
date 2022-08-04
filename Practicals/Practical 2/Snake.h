#pragma once
#include "Enemy.h"

class Snake: public Enemy {
public:
    Snake(int hp, int dmg, std::string& atk, std::string& def);
    ~Snake() override = 0;
    bool hitSquadMember(SquadMember* z) override;
    bool getHit(SquadMember* z) override;
    void celebrate() override;
    void die() override;
};
