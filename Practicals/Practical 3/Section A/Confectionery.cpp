//
// Created by Francois Smith on 2022/08/23.
//

#include "Confectionery.h"

#include <utility>
int Confectionery::count = 0;

Confectionery::~Confectionery()
{
    std::cout << "Confectionery " << this->id << " has been destroyed" << std::endl;
}

Confectionery::Confectionery(std::string manufacturer, std::string type, double price) : manufacturer{std::move(manufacturer)}, type{std::move(type)}, price(price)
{
    id = count++;
}

std::string Confectionery::getDescription()
{
    return "Confectionery " + std::to_string(id) + ": " + manufacturer + " " + type + " | R" + std::to_string(price);
}
