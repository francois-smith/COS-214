//
// Created by Francois Smith on 2022/08/24.
//

#pragma once
#include "ConfectioneryFactory.h"
#include "Areo.h"
#include "MilkyBar.h"

class NestleFactory: public ConfectioneryFactory
{
public:
    ~NestleFactory() override = default;
    Chocolate* createChocolate(bool bar) override;
    AeratedChocolate* createAeratedChocolate(int density) override;
};
