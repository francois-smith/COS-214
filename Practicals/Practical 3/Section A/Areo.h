//
// Created by Francois Smith on 2022/08/23.
//

#pragma once
#include "AeratedChocolate.h"

class Areo: public AeratedChocolate
{
public:
    explicit Areo(int bubblspccm) : AeratedChocolate("Nestle", 33.99, bubblspccm){};
};