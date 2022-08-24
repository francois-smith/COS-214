//
// Created by Francois Smith on 2022/08/23.
//

#pragma once
#include <string>
#include <iostream>

class Confectionery
{
public:
    Confectionery(std::string manufacturer, std::string type, double price);
    virtual ~Confectionery();
    virtual std::string getDescription();

private:
    std::string manufacturer;
    std::string type;
    double price;
    int id;
    static int count;
};