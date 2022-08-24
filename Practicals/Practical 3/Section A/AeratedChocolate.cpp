//
// Created by Francois Smith on 2022/08/23.
//

#include "AeratedChocolate.h"

AeratedChocolate::AeratedChocolate(std::string manufacturer, double price, int bubblspccm): Confectionery(std::move(manufacturer), "Aerated Chocolate", price)
{
    bubblespccm = bubblspccm;
}

std::string AeratedChocolate::getDescription()
{
    return Confectionery::getDescription() + " | Bubbles Density: " + std::to_string(bubblespccm);
}
