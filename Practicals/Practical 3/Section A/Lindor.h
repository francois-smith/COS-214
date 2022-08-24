//
// Created by Francois Smith on 2022/08/23.
//

#pragma once
#include "Chocolate.h"

class Lindor: public Chocolate
{
public:
    explicit Lindor(bool slab) : Chocolate("Lindt", 59.99, slab){};
};