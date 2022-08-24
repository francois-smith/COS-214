//
// Created by Francois Smith on 2022/08/24.
//

#include "AgileBattleState.h"

AgileBattleState::AgileBattleState()
{
    this->battleStyle = "Agile";
}

int AgileBattleState::handle(std::string name, int damage)
{
    std::cout << name << " has selected an agile battle state, and is allowed two battle attacks in one turn and will deal " << damage*0.75 << " points" << std::endl;
    return (int)(damage*0.75);
}