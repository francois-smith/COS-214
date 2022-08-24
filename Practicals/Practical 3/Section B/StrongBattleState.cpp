//
// Created by Francois Smith on 2022/08/24.
//

#include "StrongBattleState.h"

StrongBattleState::StrongBattleState()
{
    this->battleStyle = "Strong";
}

int StrongBattleState::handle(std::string name, int damage)
{
    std::cout << name << " has selected a strong battle state, and will inflict " << damage*2 << " points on the next battle attack but misses the following attack turn." << std::endl;
    return damage*2;
}