//
// Created by Francois Smith on 2022/08/23.
//

#pragma once
#include "AeratedChocolate.h"

class DiaryMilkBubbly: public AeratedChocolate
{
public:
    explicit DiaryMilkBubbly(int bubblspccm) : AeratedChocolate("Cadbury", 11.89, bubblspccm){};
};