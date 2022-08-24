//
// Created by Francois Smith on 2022/08/24.
//

#pragma once
#include "BattleState.h"

class AgileBattleState: public BattleState
{
public:
    AgileBattleState();
    ~AgileBattleState() override = default;
    int handle(std::string name, int damage) override;
};