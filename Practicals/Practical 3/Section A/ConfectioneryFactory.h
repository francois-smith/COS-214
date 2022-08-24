//
// Created by Francois Smith on 2022/08/23.
//

#pragma once
#include "Chocolate.h"
#include "AeratedChocolate.h"

class ConfectioneryFactory
{
public:
    virtual ~ConfectioneryFactory() = default;
    virtual Chocolate* createChocolate(bool bar) = 0;
    virtual AeratedChocolate* createAeratedChocolate(int density) = 0;
};
