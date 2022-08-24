//
// Created by Francois Smith on 2022/08/23.
//

#pragma once
#include "Chocolate.h"

class DiaryMilk: public Chocolate
{
public:
    explicit DiaryMilk(bool slab) : Chocolate("Cadbury", 17.99, slab){};
};
