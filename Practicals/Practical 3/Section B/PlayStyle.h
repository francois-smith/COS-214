//
// Created by Francois Smith on 2022/08/24.
//

#pragma once
#include <string>

class PlayStyle
{
public:
    virtual std::string attack() const = 0;
    virtual ~PlayStyle() = default;
};
