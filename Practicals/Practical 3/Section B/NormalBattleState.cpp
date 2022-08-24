//
// Created by Francois Smith on 2022/08/24.
//

#include "NormalBattleState.h"

NormalBattleState::NormalBattleState()
{
    this->battleStyle = "Normal";
}

int NormalBattleState::handle(std::string name, int damage)
{
    std::cout << name << " has no special battle state, normal battle attack will deal " << damage << " points" << std::endl;
    return damage;
}
