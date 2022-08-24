//
// Created by Francois Smith on 2022/08/24.
//

#pragma once
#include "BattleState.h"

class NormalBattleState: public BattleState
{
public:
    NormalBattleState();
    ~NormalBattleState() override = default;
    int handle(std::string name, int damage) override;
};
