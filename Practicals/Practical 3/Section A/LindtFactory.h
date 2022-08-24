//
// Created by Francois Smith on 2022/08/24.
//

#pragma once
#include "ConfectioneryFactory.h"
#include "Lindor.h"

class LindtFactory: public ConfectioneryFactory
{
public:
    ~LindtFactory() override = default;
    Chocolate* createChocolate(bool bar) override;
    AeratedChocolate* createAeratedChocolate(int density) override;
};
