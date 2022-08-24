//
// Created by Francois Smith on 2022/08/23.
//

#pragma once
#include "Confectionery.h"

class AeratedChocolate: public Confectionery
{
public:
    AeratedChocolate(std::string manufacturer, double price, int bubblspccm);
    std::string getDescription() override;

private:
    int bubblespccm;
};