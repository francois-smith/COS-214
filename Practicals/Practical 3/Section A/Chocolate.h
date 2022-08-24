//
// Created by Francois Smith on 2022/08/23.
//

#pragma once
#include "Confectionery.h"

class Chocolate: public Confectionery
{
public:
    Chocolate(std::string manufacturer, double price, bool slab);
    std::string getDescription() override;

private:
    bool bSlab;
};
