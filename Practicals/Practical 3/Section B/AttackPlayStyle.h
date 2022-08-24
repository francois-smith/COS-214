//
// Created by Francois Smith on 2022/08/24.
//

#pragma once
#include "PlayStyle.h"

class AttackPlayStyle: public PlayStyle
{
public:
    std::string attack() const override;
    ~AttackPlayStyle() override = default;
};

