//
// Created by Francois Smith on 2022/08/23.
//

#include "Chocolate.h"

Chocolate::Chocolate(std::string manufacturer, double price, bool slab) : Confectionery(std::move(manufacturer), "Chocolate", price)
{
    bSlab = slab;
}

std::string Chocolate::getDescription() {
    return Confectionery::getDescription() + " | Size: " + (bSlab ? "Slab" : "Bar");
}
