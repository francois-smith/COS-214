//
// Created by Francois Smith on 2022/08/24.
//

#pragma once
#include "ConfectioneryFactory.h"
#include "DiaryMilkBubbly.h"
#include "DiaryMilk.h"

class CadburyFactory: public ConfectioneryFactory
{
public:
    ~CadburyFactory() override = default;
    Chocolate* createChocolate(bool bar) override;
    AeratedChocolate* createAeratedChocolate(int density) override;
};
