//
// Created by Francois Smith on 2022/08/23.
//

#pragma once
#include "Chocolate.h"

class MilkyBar: public Chocolate
{
public:
    explicit MilkyBar(bool slab) : Chocolate("Nestle", 32.89, slab){};
};