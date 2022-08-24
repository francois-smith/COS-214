//
// Created by Francois Smith on 2022/08/24.
//

#pragma once
#include <string>
#include <iostream>

class BattleState
{
public:
    virtual int handle(std::string name, int damage) = 0;
    virtual ~BattleState() = default;
    std::string getBattleStyle() const;

protected:
    std::string battleStyle;
};
