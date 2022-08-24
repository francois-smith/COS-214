//
// Created by Francois Smith on 2022/08/24.
//

#pragma once
#include "BattleState.h"

class StrongBattleState: public BattleState
{
public:
    StrongBattleState();
    ~StrongBattleState() override = default ;
    int handle(std::string name, int damage) override;
};
