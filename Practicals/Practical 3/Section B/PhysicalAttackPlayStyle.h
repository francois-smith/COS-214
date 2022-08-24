//
// Created by Francois Smith on 2022/08/24.
//

#pragma once
#include "PlayStyle.h"

class PhysicalAttackPlayStyle: public PlayStyle
{
public:
    std::string attack() const override;
    ~PhysicalAttackPlayStyle() override = default;
};

