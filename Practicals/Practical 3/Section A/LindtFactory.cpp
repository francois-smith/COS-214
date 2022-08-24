//
// Created by Francois Smith on 2022/08/24.
//

#include "LindtFactory.h"

Chocolate* LindtFactory::createChocolate(bool bar)
{
    return new Lindor(bar);
}

AeratedChocolate* LindtFactory::createAeratedChocolate(int density)
{
    return nullptr;
}
