//
// Created by Francois Smith on 2022/08/24.
//

#include "CadburyFactory.h"

Chocolate* CadburyFactory::createChocolate(bool bar)
{
    return new DiaryMilk(bar);
}

AeratedChocolate* CadburyFactory::createAeratedChocolate(int density)
{
    return new DiaryMilkBubbly(density);
}
